#include<iostream>
#include<fstream>
#include<boost/filesystem.hpp>
#include<stdio.h>
#include <sstream>
#include <string>

int main()
{
        namespace bf=boost::filesystem;//简单别名

        //filesystem中最基本的类型
        bf::path path("/home/cc2/test");

        //对当前的目录的操作
        bf::path old_cpath=bf::current_path(); //取得当前目录

        bf::path file_path = path / "file.txt"; //path重载了 / 运算符

        //判断文件存在性
        if(bf::exists(path))
        {
                std::ofstream out(path.filename().c_str());
                if(!out) return 1;
                out << "一个测试文件\n";
                out.close();
        }
        else
        {
                std::cout << path << "不存在\n";
                //目录不存在，创建
                bf::create_directory(path);

                std::ofstream out(file_path.c_str());
                if(!out.is_open())
                {
                    return 1;
                }
                else
                {
                    out << "一个测试文件\n";
                    out << "another file!\n";
                    out.close();
                }

        }

        bf::current_path(path); //设置当前为/home

        if(bf::is_regular_file(path))
        {
                std::cout << path << "是普通文件\n";
                std::cout << path << ": 大小为" << bf::file_size(path) <<'\n';
                bf::create_symlink(file_path, "/tmp/test/file-symlink");
        }

        if(bf::exists(file_path))
        {
                std::ifstream in(file_path.c_str());
                std::cout <<"file_path.filename():" <<file_path.filename()
                         <<std::endl;

                if(!in.is_open())
                {
                    std::cout << "Error opening file"; exit (1);
                }

                std::string line;
                while (std::getline(in,line))
                {

                    std::cout << line <<std::endl;
                }
        }
        else
        {
                std::cout << file_path << "不存在\n";
        }

        bf::current_path(old_cpath);

        bf::remove(file_path);//删除文件file_path
        bf::remove_all(path);//递归地删除

        return 0;
}
