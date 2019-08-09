#ifndef EX_15_21_22_H
#define EX_15_21_22_H
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class File {
public:
	File() = default;
	File(const string &name, std::size_t sz):
		fileName(name), size(sz) {}
	string getFileName() const {return fileName;}
	std::size_t getFileSize() const {return size;}
protected:
	string fileName;
	std::size_t size = 0;
};

class Pictrue : public File {
public:
	Pictrue() = default;
	Pictrue(const string &name, std::size_t sz, std::size_t wdth, std::size_t hght):
		File(name, sz), width(wdth), height(hght) {}
	virtual void show() const {
		cout << "Pictrue ";
		printInfo();
	}
protected:
	void printInfo() const {
		cout << "File: " << fileName << "Size: " << size << " # width: " << width << " height: " << height << endl; 
	}
	std::size_t width = 0;		// 图像宽度
	std::size_t height = 0;		// 图像高度
};
class Gif : public Pictrue {
public:
	Gif() = default;
	Gif(const string &name, std::size_t sz, std::size_t wdth, std::size_t hght, std::size_t keepTime):
		Pictrue(name, sz, wdth, hght), time(keepTime) {}
	void show() const override {
		cout << "Gif ";
		printInfo();
	}
private:
	std::size_t time = 1;
};
class Tiff : public Pictrue {
public:
	Tiff() = default;
	Tiff(const string &name, std::size_t sz, std::size_t wdth, std::size_t hght):
		Pictrue(name, sz, wdth, hght){}
	void show() const override {
		cout << "Tiff ";
		printInfo();
	}
};
class Jpeg : public Pictrue {
public:
	Jpeg() = default;
	Jpeg(const string &name, std::size_t sz, std::size_t wdth, std::size_t hght):
		Pictrue(name, sz, wdth, hght){}
	void show() const override {
		cout << "Jpeg ";
		printInfo();
	}
};
class Bmp : public Pictrue {
public:
	Bmp() = default;
	Bmp(const string &name, std::size_t sz, std::size_t wdth, std::size_t hght):
		Pictrue(name, sz, wdth, hght){}
	void show() const override {
		cout << "Bmp ";
		printInfo();
	}
};
#endif