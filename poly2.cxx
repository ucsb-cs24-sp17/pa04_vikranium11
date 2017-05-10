//Vikram Tharakan 5/9/11
//poly2.cxx

#include "poly2.h"
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;
namespace main_savitch_5
{
  // CONSTRUCORS AND DESTRUCTOR
  polynomial::polynomial(double c, unsigned int exponent){}
  polynomial::polynomial(const polynomial& source){}
  polynomial::~polynomial( ){}

  // MODIFICATION MEMBER FUNCTIONS
  polynomial& polynomial::operator =(const polynomial& source){}
  void polynomial::add_to_coef(double amount, unsigned int exponent){}
  void polynomial::assign_coef(double coefficient, unsigned int exponent){}
  void polynomial::clear( ){}

  // CONSTANT MEMBER FUNCTIONS
  double polynomial:: coefficient(unsigned int exponent) const{}
  polynomial polynomial::derivative( ) const{}
  double polynomial::eval(double x) const{}
  void polynomial::find_root(
		 double& answer,
		 bool& success,
		 unsigned int& iterations,
		 double guess,
		 unsigned int maximum_iterations,
		 double epsilon
		 )
    const{}
  unsigned int polynomial::next_term(unsigned int e) const{}
  unsigned int polynomial::previous_term(unsigned int e) const{}

  // NON-MEMBER BINARY OPERATORS
  polynomial operator +(const polynomial& p1, const polynomial& p2){}
  polynomial operator -(const polynomial& p1, const polynomial& p2){}
  polynomial operator *(const polynomial& p1, const polynomial& p2){}

  // NON-MEMBER OUTPUT FUNCTION
  std::ostream& operator << (std::ostream& out, const polynomial& p){}

  // PRIVATE MEMBER FUNCTION (to aid the other functions)
  void polynomial::set_recent(unsigned int exponent) const{
    if(exponent == 0){
      recent_ptr->fore();
    }
    else if(exponent >= current_degree){
      recent_ptr->back();
    }
    else if(exponent!=0 && exponent< recent_ptr->exponent()){
      //recent_ptr->
    }
    else{
      recent_ptr->set_exponent(exponent);
    }

  }  

}
  
