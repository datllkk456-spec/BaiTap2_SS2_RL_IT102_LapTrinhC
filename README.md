# GrabRide Fare Calculator

## 1. Phân tích bài toán I/O

### Input

| Tên biến | Kiểu dữ liệu | Ý nghĩa |
|---|---|---|
| `vehicle_type` | `int` | 1 = GrabBike, 2 = GrabCar |
| `distance` | `double` | Khoảng cách chuyến đi, đơn vị km |
| `is_peak_or_rain` | `int` | 1 = có phụ phí, 0 = bình thường |

### Output

- Nếu dữ liệu không hợp lệ: in thông báo lỗi và dừng chương trình.
- Nếu dữ liệu hợp lệ: hiển thị loại xe, cước cơ sở, phụ phí và tổng cước.

## 2. Phân tích giải pháp

### Bước 1: Kiểm tra khoảng cách

- Nếu `distance <= 0` hoặc `distance > 300`: báo lỗi và dừng.
- Nếu hợp lệ: tiếp tục.

### Bước 2: Kiểm tra mã loại xe

- `1`: GrabBike.
- `2`: GrabCar.
- Giá trị khác: báo lỗi và dừng.

### Bước 3: Kiểm tra phụ phí

- `0`: không có phụ phí.
- `1`: áp dụng hệ số `1.2`.
- Giá trị khác: báo lỗi và dừng.

### Bước 4: Tính cước cơ sở

**GrabBike:**
- `distance <= 2`: 12.000 VNĐ.
- `distance > 2`: `12000 + (distance - 2) * 4500`.

**GrabCar:**
- `distance <= 2`: 25.000 VNĐ.
- `distance > 2`: `25000 + (distance - 2) * 10000`.

### Bước 5: Tính tổng cước

- Không phụ phí: tổng = cước cơ sở.
- Có phụ phí: tổng = cước cơ sở × 1.2.

## 3. Pseudocode

```text
Nhập vehicle_type, distance, is_peak_or_rain

Nếu distance <= 0 hoặc distance > 300
    Báo lỗi
    Dừng

Nếu vehicle_type khác 1 và 2
    Báo lỗi
    Dừng

Nếu is_peak_or_rain khác 0 và 1
    Báo lỗi
    Dừng

Nếu vehicle_type = 1
    Nếu distance <= 2
        base_fare = 12000
    Ngược lại
        base_fare = 12000 + (distance - 2) * 4500
Ngược lại
    Nếu distance <= 2
        base_fare = 25000
    Ngược lại
        base_fare = 25000 + (distance - 2) * 10000

Nếu is_peak_or_rain = 1
    total_fare = base_fare * 1.2
    surcharge = base_fare * 0.2
Ngược lại
    surcharge = 0
    total_fare = base_fare

Hiển thị kết quả
```

## 4. Test Cases

| Trường hợp | Input | Kết quả mong đợi |
|---|---|---|
| GrabBike 2 km, bình thường | `1, 2.0, 0` | 12.000 VNĐ |
| GrabBike 3 km, bình thường | `1, 3.0, 0` | 16.500 VNĐ |
| GrabCar 2 km, bình thường | `2, 2.0, 0` | 25.000 VNĐ |
| GrabCar 3 km, có phụ phí | `2, 3.0, 1` | 42.000 VNĐ |
| Khoảng cách âm | `1, -1, 0` | Báo lỗi khoảng cách |
| Khoảng cách vượt giới hạn | `1, 301, 0` | Báo lỗi khoảng cách |
| Mã xe không hợp lệ | `3, 2, 0` | Báo lỗi mã loại xe |
| Mã phụ phí không hợp lệ | `1, 2, 5` | Báo lỗi trạng thái phụ phí |
| Chuyến rất ngắn | `1, 0.3, 0` | 12.000 VNĐ |
