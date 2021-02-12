#include<fstream>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
#include<string>


int read_file(std::string & img_path, char *& buffer) {
    std::streampos begin, end;
    std::ifstream ifs(img_path.c_str(), std::ios::in | std::ios::binary);

    begin = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    end = ifs.tellg();
    std::streamsize size = end - begin;

    buffer = (char *) malloc(size);

    ifs.seekg(0, std::ios::beg);
    ifs.read(buffer, size);

    ifs.close();

    return size;
}

int write_file(std::string & img_path, char *& buffer, int n_bytes) {
    std::ofstream ofs(img_path.c_str(), std::ios::binary | std::ios::out);
    ofs.seekp(std::ios::beg);

    ofs.write(buffer, n_bytes);

    ofs.close();

    return 0;
}

int main(int argc, char** argv ) {
    std::string img_path = "/home/elcid/Pictures/Temporary/frame1.jpg";
    std::string out_path = "/home/elcid/Pictures/Temporary/frame2.jpg";

    char * buffer;

    int n_bytes = read_file(img_path, buffer);

    std::vector<uchar> buff_vec(buffer, buffer + n_bytes);

    cv::Mat img(buff_vec);

    std::cout << img.size() << std::endl;

    cv::Mat decoded_img = cv::imdecode(img, cv::IMREAD_ANYCOLOR);

    cv::imwrite(out_path, decoded_img);

    std::cout << decoded_img.size() << std::endl;

    std::cout << "Done!" << std::endl;

    return 0;
}
