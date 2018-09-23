/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
          vector<Interval> sum;
          int flag = 0;
          for (int i = 0; i < intervals.size(); i++) {
              if (newInterval.start <= intervals[i].start
                && newInterval.end >= intervals[i].end) {
                  continue;
              }
              if (newInterval.start <= intervals[i].start
                && newInterval.end >= intervals[i].start
                && newInterval.end <= intervals[i].end) {
                  newInterval.end = intervals[i].end;
              }
              if (newInterval.start >= intervals[i].start
                && newInterval.start <= intervals[i].end
                && newInterval.end >= intervals[i].end) {
                  newInterval.start = intervals[i].start;
              }
              if (newInterval.start >= intervals[i].start
                && newInterval.end <= intervals[i].end) {
                  sum.push_back(intervals[i]);
                  flag = 1;
              }
              if (newInterval.end < intervals[i].start) {
                  if (flag == 0) sum.push_back(newInterval);
                  flag = 1;
                  sum.push_back(intervals[i]);
              }
              if (newInterval.start > intervals[i].end){
                  if (i == intervals.size() && flag == 0
                  || i != intervals.size()-1 && newInterval.end < intervals[i+1].start) {
                      sum.push_back(intervals[i]);
                      sum.push_back(newInterval);
                      flag = 1;
                  }
                  else sum.push_back(intervals[i]);
              }
          }
          if (flag == 0) sum.push_back(newInterval);
          return sum;
    }
};
