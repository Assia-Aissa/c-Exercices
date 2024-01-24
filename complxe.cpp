#include <iostream>
#include <math.h>

using namespace std;
class complexe{
    float re;
    float im;

public:
    complexe();
    complexe(float,float);
    complexe(complexe &);
    complexe& operator+(const complexe &);
    complexe& operator-(const complexe &);
    complexe& operator*(const complexe &);
    complexe& operator=(const complexe &);
    float norme();
    friend complexe& somme(const complexe &,const complexe &);
    friend ostream& operator<<(ostream &out, const complexe &b);
    friend istream& operator>>(istream &in, complexe &b);


};
complexe::complexe(){
   re=0;
   im=0;
}
complexe::complexe(float a, float b){
   re=a;
   im=b;
}
complexe::complexe(complexe &a){
   re=a.re;
   im=a.im;

}
complexe& complexe::operator+(const complexe &a){
  static complexe res;
  res.re=re+a.re;
  res.im=im+a.im;

    return res;
  }
complexe& complexe::operator-(const complexe &a){
  static complexe res;
  res.re=re-a.re;
  res.im=im-a.im;
   return res;
}
complexe& complexe::operator*(const complexe &B) {
		static complexe res;
		res.re = re*B.re - im*B.im ;
		res.im = im*B.re + re*B.im;

		return res;
}
complexe& complexe::operator=(const complexe &a){

   if(this!=&a){
    re=a.re;
    im=a.im;
   }
   return *this;
	//this is 
}
float complexe::norme(){
    float result;
        result=sqrt(re*re+im*im);

		return result;

}
complexe& somme(const complexe &a,const complexe &b){
    static complexe res;
    res.re=a.re+b.re;
    res.im=a.im+b.im;
    return res;
}
istream& operator>>(istream &in, complexe &b){
    in>>b.re;
    in>>b.im;
    return in;
}
ostream& operator<<(ostream &out, const complexe &b){
	//good now 

   if( b.re==0 ){

         if( b.im < 0 )
             out<<b.im<<"i"<< endl;
         else if( b.im > 0 )

                out<<b.im<<"i"<< endl;
                else
                    out<<b.im<< endl;
   }
    else
        if( b.im < 0 )
             out<<b.re<<b.im<<"i"<< endl;
        else if( b.im > 0 )

                out<<b.re<<"+"<<b.im<<"i"<< endl;
             else
                    out<<b.re<< endl;


        return out;
   }

int main()
{
    complexe a(7,-3), b(-5,2);
    complexe c(b);
	complexe d r ;
	d=b;
		r=d*b;
    c=a;
    cout<<a;
    cout<<c<<endl;
cout<<c;
    c=a*b;
    cout<<c;
    b=somme(a,c);
    cout<<b;
	

    return 0;
}
