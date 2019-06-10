# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Reflection 
In this section, I'll address two major take-aways from the project. The first one is how each coefficient (k_p, k_d and k_i) affect the performance of the controller. 
### Effect of K_p, K_i, and K_d
* Kp: Clearly, K_p is the proportional gain of the cross track error. It is directly related to the converging speed of the lateral offset. Based on the experiment done over the project, the larger K_p is, The quick the cte converges to zero. However, if we have a Kp that is too large, the overshoot amplitude is also quite large, which is a side effect of having large proportional gain. 

* Kd: The differential gain takes care of the overshoot issue. It behaves like a damper that mitigate the aggresive "coming back" cased by the proportional gain. In the project, I also tested the performance of the controller at different speed levels. It turns out that the larger cruise speed we have, we need a larger differential gain. 

* Ki: In our case, the intergal gain was not quite useful since we didn't introduce any disturbance in steering wheel. In reality, the effect of intergal gain is to kill the steady state error. We can reveal this by adding a constant disturbance to the steering value. Check out the vedio I put in the folder ```videos/I-control-effect```. In both veiods, a 0.3 steering offset was introduced, however, only the one with i-controller was able to correct the disturbance and drive the vehicle back to the center line. 

### How to tune the hyperparameters (K_p, K_i, and K_d)
Since our steering value can not live outside the range [-1 1], we need to prevent the values of steer_value to be too large. therefore, we constraint the value of k_p, k_i and k_d to be relatively small "~0.5". Then we manually tune the parameters based on the rule of thumb that: P first, D second and I last. The reason behind is that we want to quickly choose a proportional gain that drives the vehicle back to the center line without too much overshoot. Next, we increase the differential gain to mitigate the overshoot. If the vehicle behaves well enough, we don't need to add any intergral gain unless we observe a obvious steady state error. 

Thanks so much for the Udacity community and I really appreciate your hard working making this fantastic course. 


