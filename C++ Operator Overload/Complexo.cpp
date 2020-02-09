#include<iostream>
#include<cmath>

class complex{
private:
	double real;
	double imagin;
	double mag;
	double phase;
	
public:
	complex(double real, double imagin){
		this->real = real;
		this->imagin = imagin;
		this->mag = sqrt(pow(this->real, 2) + pow(this->imagin, 2));
		this->phase = atan(this->imagin/this->real);
	}
	//~complex();
	
	complex operator+(complex& c){
		return complex(this->real + c.real, this->imagin + c.imagin);
	}

	complex operator-(complex& c){
		return complex(this->real - c.real, this->imagin - c.imagin);
	}

	complex operator*(complex& c){
		return complex(this->real*c.real - this->imagin*c.imagin, this->real*c.imagin + this->imagin*c.real);
	}

	complex operator/(complex& c){
		double r = this->real*c.real + this->imagin*c.imagin;
		double i = -this->real*c.imagin + this->imagin*c.real;
		double den = pow(c.real,2) + pow(c.imagin,2);
		return complex(r/den, i/den);
	}

	void describe(){
		std::cout << "Real: " << this->real << std::endl;
		std::cout << "Imaginary: " << this->imagin << std::endl;
		std::cout << "Magnitude: " << this->mag << std::endl;
		std::cout << "Phase: " << this->phase << " rad" << std::endl;
	}

	void show(){
		std::cout << "Number: " << this->real << " + " << this->imagin << "j" << std::endl;
	}
};

int main(int argc, char const *argv[]){
	complex c1(2, 3), c2(5, 3), c3(6, 1);

	complex c = c1 * c2 + c3;

	c1.show();
	c2.show();
	c3.show();
	c.describe();
	c.show();
	return 0;
}
