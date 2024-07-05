# Quan_ly_Chuyen_Bay

**Mình làm đề tài 3 của thầy Thư:**
```c++
3. Quản lý các chuyến bay nội địa thuộc 1 hăng hàng không: Ta toå chöùc caùc danh saùch sau: 
- Máy bay : mảng con trỏ có tối đa 300 máy bay. Mỗi máy bay có các thông tin (Số hiệu MB (C15), loại máy bay (C40),  số dãy, số dòng) ;  Mỗi máy bay có 1 số hiệu duy nhất; (số chỗ = số dãy * số dòng ), số chỗ >=20
Nếu số dãy = 5 nghĩa là máy bay có các dãy A, B, C, D, E; Nếu số dòng = 20 nghĩa là máy bay có các hàng ghế được đánh số từ 1 đến 20. Kết hợp dãy và hàng ghế ta sẽ có số vé.
Theo ví dụ trên, ta có 100 vé với các số vé A01, A02, ...., A19, A20, …, E19, E20
- Chuyến bay : danh sách liên kết đơn ( Mã CB (C15),  Ngày giờ khởi hành, sân bay đến , trạng thái, Số hiệu MB, danh sách vé). Mỗi chuyến bay có 1 mã duy nhất; trạng thái chuyến bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé,3: hoàn tất ; danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó. Danh sách vé được cấp phát bộ nhớ tự động dựa vào số chỗ của máy bay thực hiện chuyến bay. Danh sách chuyến bay luôn có sẵn thứ tự theo mã chuyến bay.
- Hành khách: cây nhị phân tìm kiếm cân bằng(Số CMND , Ho, Ten,  Phai)
Chương trình có các chức năng sau: 
a/ Cập nhập danh sách các máy bay (thêm / xóa / hiệu chỉnh)
b/ Cập nhật chuyến bay: cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của chuyến bay , sân bay đến, số hiệu máy bay, hủy chuyến.
c/ Đặt vé: cho phép đặt vé trên 1 chuyến bay; nếu thông tin hành khách chưa có thì tự động cập nhật vào danh sách hành khách, nếu có rồi thì in ra màn hình để kiểm tra. Mỗi vé đều phải ghi nhận số CMND của hành khách; nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước. Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé.
d/ Hủy vé: cho phép hủy vé đã đặt của hành khách.
e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:
DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ######
Ngày giờ khởi hành: dd/mm/yyyy hh:mm.  Nơi đến : xxxxxxxxxxx

	STT	SỐ VÉ		SỐ CMND	HỌ TÊN	PHÁI
f/ In danh sách các chuyến bay khởi hành trong  ngày dd/mm/yyyy đến nơi XXXX   (cho biết cụ thể số lượng các vé còn trống và giờ khởi hành)
g/ In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X. 
h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự  số lượt thực hiện giảm dần. Kết xuất:
	Số hiệu máy bay		Số lượt thực hiện chuyến bay
```

## Tính năng

* Tính năng 1
* Tính năng 2
* Tính năng 3

## Cách sử dụng

1. Cài đặt dự án
2. Sử dụng tính năng 1
3. Sử dụng tính năng 2
4. Sử dụng tính năng 3

## Giấy phép

MIT License

## Liên hệ

* Email: [email protected]
* Website: https://www.example.com