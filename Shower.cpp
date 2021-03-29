#include<iostream>
using namespace std;
#include<string.h>
#include<fstream>
class ngaythang{
protected:
    int ngay;
    int thang;
    int nam;
public:
    void setNgaylapdonhang(){
        cout<<"Ngay lap don hang: ";
        cin>>this->ngay>>this->thang>>this->nam;
    }
    string returndate(){
        return to_string(ngay)+'/'+to_string(thang)+'/'+to_string(nam);
    }
};

class thongtinkhachhang{
protected:
    string makhachhang;
    string tenkhachhang;
    string diachi;
    string dienthoai;
public:
    void setThongtinkhachhang(){
        cout<<"Thong tin khach hang: "<<endl;
        cout<<"Ma khach hang: ";
        cin>>this->makhachhang;
        cout<<"Ten khach hang: ";
        cin>>this->tenkhachhang;
        cout<<"Dia chi: ";
        cin>>this->diachi;
        cout<<"So dien thoai: ";
        cin>>this->dienthoai;
    }
    string thongtin(){
        string output="Thong tin khach hang: "+ makhachhang+" "+tenkhachhang+" "+diachi+" "+dienthoai+"\n";
        return output;
    }
};

class nuochoa{
protected:
    string maso;
    string loainuochoa;
    double dungtich;
    double dongia;
public:
    nuochoa(){}
    void setNuochoa();
    double giaNuochoa();
    string outputthongtin();
};

class nuochoahong:public nuochoa{
public:
    void setNuochoa(){
        cout<<"Ma so:";
        cin>>this->maso;
        this->loainuochoa="hoa hong";
        cout<<"Loai nuoc hoa: hoa hong"<<endl;
        cout<<"Dung tich: ";
        cin>>this->dungtich;
        this->dongia=20*this->dungtich;
    }
    double giaNuochoa(){return this->dongia;}

    string outputthongtin(){
        string output="Nuoc hoa: "+maso+" "+loainuochoa+" "+to_string(dungtich)+" "+to_string(dongia);
        return output;
    }
};

class nuochoacuc:public nuochoa{
public:
    void setNuochoa(){
        cout<<"Ma so:";
        cin>>this->maso;
        this->loainuochoa="hoa cuc";
        cout<<"Loai nuoc hoa: hoa cuc"<<endl;
        cout<<"Dung tich: ";
        cin>>this->dungtich;
        this->dongia=15*this->dungtich;
    }
    double giaNuochoa(){return this->dongia;}

    string outputthongtin(){
        string output="Nuoc hoa: "+maso+" "+loainuochoa+" "+to_string(dungtich)+" "+to_string(dongia);
        return output;
    }
};

class daugoi{
protected:
    string maso;
    string loaidaugoi;
    double dungtich;
    double dongia;
public:
    void setDaugoi();
    double giaDaugoi();
    string outputthongtin();
};

class daugoitockho:public daugoi{
public:
    void setDaugoi(){
        cout<<"Dau goi: "<<endl;
        cout<<"Ma so: ";
        cin>>this->maso;
        cout<<"Loai dau goi: Kho"<<endl;
        this->loaidaugoi="kho";
        cout<<"Dung tich: ";
        cin>>this->dungtich;
        this->dongia=20*this->dungtich;
    }
    double giaDaugoi(){return this->dongia;}
    string outputthongtin(){
        string output="Dau goi: "+maso+" "+loaidaugoi+" "+to_string(dungtich)+" "+to_string(dongia);
        return output;
    }
};

class daugoitocdau:public daugoi{
public:
    string output;
    void setDaugoi(){
        int num;
        cout<<"Dau goi: "<<endl;
        cout<<"Ma so: ";
        cin>>this->maso;
        cout<<"Loai dau goi: Dau"<<endl;
        this->loaidaugoi="Dau";
        cout<<"Dung tich: ";
        cin>>this->dungtich;
        cout<<"Tieu chuan (1 hay 2): ";
        cin>>num;
        if (num==1){this->dongia=30*this->dungtich;
        output="Dau goi: "+maso+" "+loaidaugoi+" "+"tieu chuan 1" +to_string(dungtich)+" "+to_string(dongia);}
        else{this->dongia=40*this->dungtich;
        output="Dau goi: "+maso+" "+loaidaugoi+" "+"tieu chuan 2" +to_string(dungtich)+" "+to_string(dongia);}
    }
    double giaDaugoi(){return this->dongia;}
    string outputthongtin(){return output;}
};

class suatam{
protected:  
    string maso;
    string loaisuatam;
    double dungtich;
    double dongia;
public:
    void setSuatam();
    double giaSuatam();
    string outputinformation();

};

class suatamdakho:public suatam{
public:
    void setSuatam(){
        cout<<"Ma so: ";
        cin>>this->maso;
        cout<<"Loai sua tam: Kho"<<endl;
        this->loaisuatam="Kho";
        cout<<"Dung tich: ";
        cin>>this->dungtich;
        this->dongia=this->dungtich*20;
    }
    double giaSuatam(){return this->dongia;}
    string outputinformation(){
        string output="Nuoc hoa: "+maso+" "+loaisuatam+" "+to_string(dungtich)+" "+to_string(dongia);
        return output;
    }
};

class suatamdanhon:public suatam{
public:
    void setSuatam(){
        cout<<"Ma so: ";
        cin>>this->maso;
        cout<<"Loai sua tam: Nhon"<<endl;
        this->loaisuatam="Nhon";
        cout<<"Dung tich: ";
        cin>>this->dungtich;
        this->dongia=this->dungtich*40;
    }
    double giaSuatam(){return this->dongia;}
    string outputinformation(){
        string output="Nuoc hoa: "+maso+" "+loaisuatam+" "+to_string(dungtich)+" "+to_string(dongia);
        return output;
    }
};

class goiSanpham{
protected:
    string magoi;
    string loaigoi;
    string tengoi;
    double giagoisanpham=0;
public:
    void setGiatri();
    double giatien();
    string outputtotal();
    string thongtingoisanpham();
};

class Romantic:public goiSanpham{
public:
    string outputfinal;
    string thongtin;
    void setGiatri(){
        int num, num1;
        cout<<"Ma goi: ";
        cin>>this->magoi;
        cout<<"Loai goi: Romantic"<<endl;
        this->loaigoi="Romantic";
        nuochoahong n;
        n.setNuochoa();
        giagoisanpham+=n.giaNuochoa();
        outputfinal=outputfinal+n.outputthongtin()+"\n";
        cout<<"Ten goi: Goi lang mang"<<endl;
        this->tengoi="Goi lang mang";
        cout<<"Chon dau goi (1-cho toc kho, 2-cho toc dau): ";
        cin>>num;
        if (num==1){
            daugoitockho k;
            k.setDaugoi();
            outputfinal+=(k.outputthongtin()+"\n");
            giagoisanpham+=k.giaDaugoi();
        }else{
            daugoitocdau d;
            d.giaDaugoi();
            outputfinal+=(d.outputthongtin()+"\n");
            giagoisanpham+=d.giaDaugoi();
        }
        cout<<"Chon sua tam (1-cho da kho, 2-cho da nhon): ";
        cin>>num1;
        if (num1==1){
            suatamdakho dk;
            dk.setSuatam();
            outputfinal+=(dk.outputinformation()+"\n");
            giagoisanpham+=dk.giaSuatam();
        }else{
            suatamdanhon dn;
            dn.setSuatam();
            outputfinal+=(dn.outputinformation()+"\n");
            giagoisanpham+=dn.giaSuatam();
        }
    }

    double giatien(){
        return this->giagoisanpham;
    }

    string outputtotal(){
        return outputfinal;
    }

    string thongtingoisanpham(){
        thongtin="Goi san pham: "+magoi+" "+loaigoi+" "+tengoi+" "+to_string(Romantic::giatien())+"\n";
        return thongtin;
    }
};

class Freshair:public goiSanpham{
public:
    string outputfinal;
    string thongtin;
    void setGiatri(){
        int num, num1;
        cout<<"Ma goi: ";
        cin>>this->magoi;
        cout<<"Loai goi: Freshair"<<endl;
        this->loaigoi="Freshair";
        this->tengoi="Huong thom ngay ngat";
        cout<<"Ten goi: Huong thom ngay ngat"<<endl;
        daugoitockho k;
        k.setDaugoi();
        giagoisanpham+=k.giaDaugoi();
        outputfinal+=(k.outputthongtin()+"\n");
        this->loaigoi="Goi tuoi mat";
        cout<<"Chon nuoc hoa (1-nuoc hoa hong, 2-nuoc hoa cuc): ";
        cin>>num;
        if (num==1){
            nuochoahong h;
            h.setNuochoa();
            outputfinal+=(h.outputthongtin()+"\n");
            giagoisanpham+=h.giaNuochoa();
        }else{
            nuochoacuc c;
            c.setNuochoa();
            outputfinal+=(c.outputthongtin()+"\n");
            giagoisanpham+=c.giaNuochoa();
        }
        cout<<"Chon sua tam (1-cho da kho, 2-cho da nhon): ";
        cin>>num1;
        if (num1==1){
            suatamdakho dk;
            dk.setSuatam();
            outputfinal+=(dk.outputinformation()+"\n");
            giagoisanpham+=dk.giaSuatam();
        }else{
            suatamdanhon dn;
            dn.setSuatam();
            outputfinal+=(dn.outputinformation()+"\n");
            giagoisanpham+=dn.giaSuatam();
        }
    }

    double giatien(){
        return this->giagoisanpham;
    }

    string outputtotal(){return outputfinal;}

    string thongtingoisanpham(){
        thongtin="Goi san pham: "+magoi+" "+loaigoi+" "+tengoi+" "+to_string(Freshair::giatien())+"\n";
        return thongtin;
    }
};

class giadonhang{
protected:
    string madonhang;
    thongtinkhachhang tt;
    ngaythang nt;
    double giadonhang;
public:
    string outputhere;
    void setThongtin(){
        int num;
        cout<<"Ma don hang: ";
        cin>>this->madonhang;
        tt.setThongtinkhachhang();
        nt.setNgaylapdonhang();
        cout<<"Nhap goi san pham (1-Romantic, 2-Freshair): ";
        cin>>num;
        if (num==1){
            Romantic r;
            r.setGiatri();
            this->giadonhang=r.giatien();
            outputhere=r.outputtotal()+r.thongtingoisanpham();
        }else{
            Freshair h;
            h.setGiatri();
            this->giadonhang=h.giatien();
            outputhere=h.outputtotal()+h.thongtingoisanpham();
        }
    }

    string outputthongtin(){
        string output="Don hang: "+madonhang+" "+nt.returndate()+" "+to_string(this->giadonhang)+"\n";
        output+=tt.thongtin();
        output+=outputhere;
        return output;
    }
};

int main(){
    giadonhang d;
    d.setThongtin();
    cout<<d.outputthongtin();
    ofstream file("danh_sach_san_pham_ve_sinh.txt");
    file<<d.outputthongtin();
    file.close();
}
