//===============================================================
// Level 1 Section 1.5 Exercise 1.5.3
// Author: Grant Liu
// Create Date: 1/8/2017
// Description: main file
//===============================================================
#include<algorithm>
#include<numeric>
#include<tuple>
#include<vector>
#include<cmath>
#include<iostream>

using std::vector;
using std::tuple;
using std::cout;
using std::endl;

using tuple_5 = tuple<double, double, double, double, double>;

//Generate a statistic report, use a vector as input and return a 5-element tuple.
tuple_5 statistic_report(const vector<double>& source){

 //Use std::minmax_element to find min and max of the source vector
  auto minmax = std::minmax_element(source.begin(), source.end());

  //Use max and min to calculate range
  double range = *minmax.second - *minmax.first;

  //Use std::accumulate to get the sum, and then compute average
  double sum = std::accumulate(source.begin(), source.end(), 0.0);
  double mean = std::accumulate(source.begin(), source.end(), 0.0) / double(source.size());

  double mean_dev = 0.0, variance = 0.0;

  //Use for_each to get the value of mean deviation, variance before being divided by size
  for_each(source.begin(), source.end(), [&](const double& element){
      mean_dev += fabs((double)(element - mean));
      variance += (element - mean) * (element - mean);
    });

  mean_dev /= source.size();
  //Calculate sample variance and std
  variance /= (source.size()-1);
  double std = sqrt(variance);

  tuple_5 result {mean, mean_dev, range, std, variance};
  return result;
}

// Calculate median and mode for a vector
tuple<double, double> medianmode(const vector<double>& source){
  int size = source.size();

  //Calculate the median according to size of vector
  double median = (size%2 == 0)? (source[size/2] + source[size/2 -1])/2.0 : source[(size-1)/2];

  vector<double> candidates; // candidates saves all possible mode from smallest to largest
  int max_freq = 0, current_freq = 1;// initialization for mode finding

  for(auto it = source.begin();it<source.end();++it){

     // if current element is equal to previous, then current_freq ++
    if (it != source.begin() && *it == *(it-1)) ++current_freq;
    else current_freq =1;

	// if current element's freq is equal to maximum freq, then add current element to candidate vector
    if (current_freq == max_freq) candidates.push_back(*it);

	// if current element's freq is larger than maximum freq, then clear the candidate vector
	// and add current element as the first candidate, update maximum freq at the same time.
    if (current_freq > max_freq){
      candidates.clear();
      candidates.push_back(*it);
      max_freq = current_freq;
    }
  }

   tuple<double, double> result {median, candidates.at(0)};
   // here I only returned median and the smallest mode. If we'd like to implement 
   // the function in remark, we can return the whole candidates vector and max_freq as well.
  return result;
}


int main(){

  //Declare data vector
  vector<double> data = {1.0, 2.3, 3.0, -2.0, -1.5, 1.0, 2.3, 5.0, -1.5, -1.5};

  tuple_5 report = statistic_report(data);

  double data_mean, data_meanDev, data_range, data_std, data_var;
  std::tie(data_mean, data_meanDev, data_range, data_std, data_var) = report;

  cout<<"data_mean: "<<data_mean<<endl;
  cout<<"data_meanDev: "<<data_meanDev<<endl;
  cout<<"data_range: "<<data_range<<endl;
  cout<<"data_std: "<<data_std<<endl;
  cout<<"data_var: "<<data_var<<endl;

  std::sort(data.begin(), data.end());

  double data_median, data_mode;
  std::tie(data_median, data_mode) = medianmode(data);
  cout<<"data_median: "<<data_median<<endl;
  cout<<"data_mode: "<<data_mode<<endl;

  return 0;
}
