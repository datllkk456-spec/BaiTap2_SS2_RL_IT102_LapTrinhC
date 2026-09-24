#include <stdio.h>

int main() {
    int vehicle_type;
    double distance;
    int is_peak_or_rain;
    double base_fare = 0.0;
    double surcharge = 0.0;
    double total_fare = 0.0;

    printf("Nhap ma loai xe (1: GrabBike, 2: GrabCar): ");
    if (scanf("%d", &vehicle_type) != 1) {
        printf("Loi: Ma loai xe khong hop le.\n");
        return 1;
    }

    printf("Nhap quang duong (km): ");
    if (scanf("%lf", &distance) != 1) {
        printf("Loi: Khoang cach khong hop le.\n");
        return 1;
    }

    printf("Co phu phi cao diem/thoi tiet? (1: Co, 0: Khong): ");
    if (scanf("%d", &is_peak_or_rain) != 1) {
        printf("Loi: Trang thai phu phi khong hop le.\n");
        return 1;
    }

    // Kiem tra khoang cach truoc khi tinh cuoc
    if (distance <= 0.0 || distance > 300.0) {
        printf("Loi: Khoang cach phai lon hon 0 va khong vuot qua 300 km.\n");
        return 1;
    }

    // Kiem tra ma loai xe
    if (vehicle_type != 1 && vehicle_type != 2) {
        printf("Loi: Ma loai xe khong hop le.\n");
        return 1;
    }

    // Kiem tra trang thai phu phi
    if (is_peak_or_rain != 0 && is_peak_or_rain != 1) {
        printf("Loi: Ma trang thai phu phi khong hop le.\n");
        return 1;
    }

    // Tinh cuoc co so theo loai xe va khoang cach
    if (vehicle_type == 1) {
        if (distance <= 2.0) {
            base_fare = 12000.0;
        } else {
            base_fare = 12000.0 + (distance - 2.0) * 4500.0;
        }
    } else {
        if (distance <= 2.0) {
            base_fare = 25000.0;
        } else {
            base_fare = 25000.0 + (distance - 2.0) * 10000.0;
        }
    }

    // Ap dung phu phi 20% neu co cao diem hoac thoi tiet xau
    if (is_peak_or_rain == 1) {
        surcharge = base_fare * 0.2;
    } else {
        surcharge = 0.0;
    }

    total_fare = base_fare + surcharge;

    printf("\n===== HOA DON GRABRIDE =====\n");

    if (vehicle_type == 1) {
        printf("Loai xe: GrabBike\n");
    } else {
        printf("Loai xe: GrabCar\n");
    }

    printf("Quang duong: %.2f km\n", distance);
    printf("Cuoc co so: %.0f VND\n", base_fare);
    printf("Phu phi: %.0f VND\n", surcharge);
    printf("Tong cuoc: %.0f VND\n", total_fare);

    return 0;
}
