#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Kd = Kd_;
  Ki = Ki_;

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // Update the proportional error
  p_error = cte;
  d_error = cte - prev_cte; 
  i_error += cte; 
  prev_cte = cte; 

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return - Kp*p_error - Kd*d_error - Ki*i_error;  // TODO: Add your total error calc here!
}