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
  polynomial::polynomial(double c, unsigned int exponent){
    head_ptr = new polynode;
    if(c>0){
      current_degree = exponent;
    }
    else{
      current_degree = 0;
    }

    
    if (c == 0) {
      tail_ptr = head_ptr;
      head_ptr -> set_exponent(0);
      head_ptr -> set_coef(0);
    }

    if(exponent ==0 && c!=0){
      tail_ptr = head_ptr;
      head_ptr -> set_coef(c);
      head_ptr -> set_exponent(0);
    }

    recent_ptr = head_ptr;
    for(int i =0; i < exponent; i++){
      polynode *p1 = new polynode;
      recent_ptr->set_fore(p1);
      p1 -> set_exponent(i+1);
      if((i+1) != exponent){
	p1-> set_coef(0);
      }
      else{
	p1-> set_coef(c);
	tail_ptr = p1;
      }
      recent_ptr = p1;
    }

      
  }
  polynomial::polynomial(const polynomial& source){}
  polynomial::~polynomial( ){}

  // MODIFICATION MEMBER FUNCTIONS
  polynomial& polynomial::operator =(const polynomial& source){}
  void polynomial::add_to_coef(double amount, unsigned int exponent){}
  void polynomial::assign_coef(double coefficient, unsigned int exponent){}
  void polynomial::clear( ){}

  // CONSTANT MEMBER FUNCTIONS
  double polynomial:: coefficient(unsigned int exponent) const{
    if(exponent <= current_degree){
      polynode *temp = head_ptr;
      for(int i = 0; i<exponent; i++){
	temp = temp->fore();
      }
      return temp -> coef();
    }
    else{
      return 0;
    }

  }
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
      recent_ptr = head_ptr;
    }
    else if(exponent >= current_degree){
      recent_ptr = tail_ptr;
    }
    else if(exponent!=0 && exponent < recent_ptr->exponent() && exponent < current_degree){
      //Iterates backward until the pointer points to the desired node
      polynode *temp_ptr = tail_ptr;
      while(temp_ptr->exponent() != exponent){
	temp_ptr->back();
      }
      recent_ptr = temp_ptr;
    }
    else if(exponent!=0 && exponent > recent_ptr->exponent() && exponent < current_degree){
      //Iterates forward until the pointer points to the desired node
      polynode *temp_ptr = recent_ptr;
      while(temp_ptr->exponent() != exponent){
	temp_ptr->fore();
      }
      recent_ptr = temp_ptr;
    }
  }


  
}
  
