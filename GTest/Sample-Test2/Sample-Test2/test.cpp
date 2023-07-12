#include "pch.h"
#include <algorithm>
enum LoaiTamGiac {
	TamGiacKhongTonTai,
	TamGiacDeu,
	TamGiacCan,
	TamGiacVuong,
	TamGiacThuong
};

LoaiTamGiac XacDinhLoaiTamGiac(double a, double b, double c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return TamGiacKhongTonTai;
	}

	if (a == b && b == c) {
		return TamGiacDeu;
	}

	if (a == b || b == c || c == a) {
		return TamGiacCan;
	}

	double maxSide = std::max(a, std::max(b, c));
	double sumSquares = a * a + b * b + c * c;

	if (2 * maxSide * maxSide == sumSquares) {
		return TamGiacVuong;
	}

	return TamGiacThuong;
}

TEST(XacDinhLoaiTamGiac, TamGiacKhongTonTai_1) {
	double x = 0, y = 1, z = 2;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x,y,z);
  EXPECT_EQ(TamGiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiac, TamGiacKhongTonTai_2) {
	double x = 1, y = 0, z = 2;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacKhongTonTai);
}
TEST(XacDinhLoaiTamGiac, TamGiacKhongTonTai_3) {
	double x = 2, y = 1, z = 0;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, TamGiacDeu) {
	double x = 1, y = 1, z = 1;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacDeu);
}

TEST(XacDinhLoaiTamGiac, TamGiacCan_1) {
	double x = 1, y = 1, z = 0.5;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiac, TamGiacCan_2) {
	double x = 0.5, y = 1, z = 1;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacCan);
}
TEST(XacDinhLoaiTamGiac, TamGiacCan_3) {
	double x = 1, y = 0.5, z = 1;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, TamGiacVuong) {
	double x = 6, y = 8, z = 10;
	double canhMax = std::max(x, std::max(y, z));
	double tongBinhPhuong = x * x + y * y + z * z;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacVuong);
}

TEST(XacDinhLoaiTamGiac, TamGiacThuong) {
	double x = 6, y = 8, z = 9;
	LoaiTamGiac TamGiac = XacDinhLoaiTamGiac(x, y, z);
	EXPECT_EQ(TamGiac, TamGiacThuong);
}



