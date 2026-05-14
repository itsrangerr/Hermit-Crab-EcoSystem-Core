# 🦀 Hermit Crab Terrarium Ecosystem Core

Dự án mô phỏng hệ thống nhúng (Embedded System) xử lý dữ liệu môi trường cho bể nuôi ốc mượn hồn. Code được tối ưu hóa ở mức bộ nhớ thấp (Low-level Memory) thông qua C-String và Pointers, không phụ thuộc vào các thư viện C++ bậc cao (như `<string>`).

## ✨ Tính năng cốt lõi (Core Features)
- **Sensor Log Parsing (C-String):** Thuật toán duyệt con trỏ thô (Raw Pointers) để bóc tách dữ liệu từ luồng log của vi điều khiển (VD: `TMP:28-HUM:82-CRAB:Violascens`). Không phát sinh thêm bộ nhớ phụ (Zero Allocation).
- **Molting Environment Checker:** Áp dụng đệ quy (Recursion) kết hợp pointer arithmetic để đánh giá mảng dữ liệu độ ẩm tuần tự, đảm bảo môi trường an toàn cho kỳ lột xác.
- **Drought Target & Rescue (Matrix Pointer):** Cấp phát động ma trận biểu đồ độ ẩm bề mặt R x C. Thuật toán tự động tìm kiếm khu vực khô hạn nhất và trả về **Địa chỉ trực tiếp (Direct Memory Address)** để hệ thống phun sương có thể can thiệp và ghi đè giá trị (Gán `*max = 85`) ngay trên RAM.
- **Safe Heap Deallocation:** Tuân thủ nghiêm ngặt nguyên lý giải phóng bộ nhớ đa chiều, loại bỏ hoàn toàn các lỗi Memory Leak và Invalid Free.

## 🛠️ Công nghệ sử dụng
- **Ngôn ngữ:** C++ (Standard)
- **Kiến trúc:** Pointers Arithmetic, Recursion, 2D Dynamic Allocation, Pass by Address.

## 🚀 Hướng dẫn biên dịch
1. Clone repository này về thiết bị:
   ```bash
   git clone https://github.com/your-username/Hermit-Crab-EcoSystem-Core.git
   ```
2. Compile file mã nguồn bằng trình biên dịch GCC:
   ```bash
   g++ main.cpp -o EcoSystem
   ./EcoSystem
   ```
3. Nhập dữ liệu độ ẩm giả lập (Ví dụ: Ma trận 3x3) để kiểm tra luồng hoạt động của hệ thống phun sương.

## 👨‍💻 Tác giả
**Phùng Tấn Khánh Đăng** 
*Khoa Công nghệ Thông tin - Đại học Mở TP.HCM*

---
*Dự án thực hành chuyên sâu nhằm nâng cao tư duy quản lý con trỏ và thao tác bộ nhớ trực tiếp trong môi trường C++.*
