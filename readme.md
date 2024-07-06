# ĐỒ ÁN QUẢN LÝ CHUYẾN BAY

# Table of Contents
- [ĐỀ BÀI](#1)
- [CHỨC NĂNG](#2)
- [LƯU Ý](#3)
- [THẦY NHẬN XÉT](#4)
- [CÀI THƯ VIỆN](#5)

 
## ĐỀ BÀI <a name="1"></a>

#### Máy bay: 
+ Mảng con trỏ có tối đa 300 máy bay. 
+ Mỗi máy bay có các thông tin (Số hiệu MB (C15), loại máy bay (C40), số chỗ)
+ Mỗi máy bay có 1 số hiệu duy nhất; số chỗ >=20

#### Chuyến bay: 
+ Danh sách liên kết đơn (Mã CB: C15, Ngày giờ khởi hành, Sân bay đến, Trạng thái, Số hiệu MB, danh sách vé). 
+ Mỗi chuyến bay có 1 mã duy nhất
+ Trạng thái chuyến bay bao gồm: 0: hủy chuyến, 1: còn vé, 2: hết vé, 3: hoàn tất
+ Danh sách vé cho biết thông tin vé trên chuyến bay, và số CMND của hành khách đã đặt vé đó. (mảng con trỏ)
+ Mỗi vé có số vé là số thứ tự trên chuyến từ số 1 đến số chỗ. Danh sách vé được cấp phát bộ nhớ tự động dựa vào số chỗ của máy bay thực hiện chuyến bay.

#### Hành khách: 
+ Cây nhị phân tìm kiếm tự cân bằng (Số CMND, Ho, Ten, Phai)

#### Chương trình có các chức năng sau: 

a/ Cập nhập danh sách các máy bay (thêm / xóa / hiệu chỉnh)      -         

b/ Cập nhật chuyến bay: cho phép lập chuyến bay mới, hiệu chỉnh ngày giờ khởi hành của chuyến bay, hủy chuyến.

c/ Đặt vé: cho phép đặt vé trên 1 chuyến bay; nếu thông tin hành khách chưa có thì tự động cập nhật vào danh sách hành khách, nếu có rồi thì in ra màn hình để kiểm tra. Mỗi vé đều phải ghi nhận số CMND của hành khách; nếu hành khách chưa có số CMND thì yêu cầu nhập thông tin hành khách trước. Trên 1 chuyến bay, mỗi hành khách chỉ được mua 1 vé. 

d/ Hủy vé: cho phép hủy vé đã đặt của hành khách.

e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay. Kết xuất:

DANH SÁCH HÀNH KHÁCH THUỘC CHUYẾN BAY ######
Ngày giờ khởi hành:   dd/mm/yyyy    hh:mm    Nơi đến: xxxxxxxxxxx

	STT	SỐ VÉ		SỐ CMND	HỌ TÊN	PHÁI


f/ In danh sách các chuyến bay khởi hành trong ngày dd/mm/yyyy đến nơi XXXX (cho biết cụ thể số lượng các vé còn trống và giờ khởi hành) 

g/ In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X. 
h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự số lượt thực hiện giảm dần. Kết xuất:
	Số hiệu máy bay		Số lượt thực hiện chuyến bay

Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập liệu làm dữ liệu bị sai.


## CHỨC NĂNG <a name="2"></a>

a) MÁY BAY (thêm, xóa, hiệu chỉnh)

- Thêm (id plane phải viết hoa,id không được trùng, số chỗ 20 - 300)
- Xóa ( Khi chưa thành lập chuyến bay)
- Chỉnh sửa:
    - Chưa thành lập chuyến bay: Sửa type và seats
    - Đã thành lập nhưng status là còn vé hoặc hết vé → chỉ cho sửa số ghế tăng dần
        (cập nhật chuyến bay số ghế tăng dần)
        
b) CHUYẾN BAY (thêm,cancle,hiệu chỉnh ngày giờ)

Danh sách tự cập nhật sold out, completed(nếu ko có ai đặt vé trả về trạng thái hủy)

- Thêm (id flight không được trùng, ngày giờ hợp lệ, thời gian ≥ 4 h từ hiện tại,khác id flight trùng id plane ≥ 12 hour từ chuyến bay đó)
- Hiệu chỉnh (chuyến còn vé hoặc hết vé , bắt lỗi thời gian nếu có hành khách khác 1 người, hiệu chỉnh từ mốc thời gian hiện tại tăng lên 1 tiếng,  không cho hiệu chỉnh trong 30 phút cuối, nếu hiệu chỉnh vào phút 29 thì kiểm tra nếu qua phút 30 thì tự động thoát ra màn hình chính, nếu hiệu chỉnh vào lúc chuyến bay đã hoàn thành thì thoát ra)
- Hủy (còn vé hoặc hết vé )

c) ĐẶT VÉ(thêm hành khách)
- màn hình đặt vé hiển thị chuyến bay còn vé hoặc đầy vé
- ko cho đặt khách đặt vé cùng ID trong chuyến bay , nếu có hiển thị chương trình hủy vé máy bay 

d) HỦY VÉ
- Hủy vé khi chuyến bay chưa hoàn thành chưa cancle, chưa tới 30 phút cuối trước khi bay

e/ In danh sách các hành khách thuộc 1 chuyến bay dựa vào mã chuyến bay
- In thông tin hành khách và số ghế lần lượt

h/ Thống kê số lượt thực hiện chuyến bay của từng máy bay
- Tạo một mảng mới lưu vị trí, và sắp xếp vị trí trên mảng đó ko làm ảnh hưởng đến danh sách máy bay

<img width="960" alt="Untitled" src="https://i.imgur.com/AicCz5q.png">
Màn hình danh sách máy bay


<img width="960" alt="Untitled" src="https://i.imgur.com/1dwCAQ7.png">
Màn hình thêm  máy bay


<img width="960" alt="image" src="https://i.imgur.com/EMKDCRk.png">
Màn hình danh sách chuyến bay

<img width="960" alt="image" src="https://i.imgur.com/pilGTRO.png">
Thêm danh chuyến bay

<img width="960" alt="Untitled" src="https://i.imgur.com/hwTTLzG.png">
Danh sách hành khách

<img width="960" alt="image" src="https://i.imgur.com/pIAekgs.png">
Danh sách vé

<img width="960" alt="image" src="https://i.imgur.com/qRF0ZZS.png">
Thống kê số lượt thực hiện máy bay


## LƯU Ý <a name="3"></a>
- Đối với con trỏ sử dụng toán tử `new` phải giải phóng vùng nhớ, đặt biệt mảng con trỏ
- Chú ý làm kĩ các file `CTDL`
- Chú ý các khi nhập id thì phải viết hoa không khoảng trắng, họ tên thì viết hoa chữ cái đầu VD `Ngoc Anh`
- Chú ý bắt các lỗi về thời gian

## THẦY NHẬN XÉT <a name="4"></a>
- Khen
  - giao diện tạm 
  
- Chê
  - Đặt vé phải gõ tay chứ chưa có chọn vé bằng click vô ghế 

- Câu hỏi phụ
  - Cho một danh sách gồm 100000 sinh viên [mã sv, tên, tuổi, giới tính ,...] trong file NHỊ PHÂN hỏi làm sao để sắp xếp file ngoài file nhanh nhất biết bộ nhớ chỉ lưu được 10000 sinh viên..... ( mình nhớ là vậy ) 
 
 ## CÀI THƯ VIỆN <a name="5"></a>
 - Đồ án của mình thì code mình tự viết, còn về phần trình bày... thì mình tham khảo của chị này, siêu siêu đỉnh đọc code chị này siêu thích luôn https://github.com/ahuynh359/Quan_Ly_Chuyen_Bay_PTITHCM
 - Kể cả phần readme.md này mình cũng copy của chị ta, chị ấy siêu đỉnh hi vọng các bạn xem chị đó,

 - Tham khảo thêm link https://github.com/ahuynh359/Graphics
 - Demo đồ án của chị ánh: https://www.youtube.com/watch?v=rGFWxpukt2s

## ĐIỂM SỐ
- 2 bọn tui được 8 điểm tại câu cuối không trả lời được vì liên quan đến file nhị phân , hơi tiếc 1 chút
Quan trọng do quá trình các bạn vấn đáp với thầy thôi nhé :3. Good luck !
