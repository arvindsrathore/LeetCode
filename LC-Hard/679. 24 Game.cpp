// https://leetcode.com/problems/24-game/

// Don't ask me how I did it, I just did it
// Thought of it as a very complex problem, but turned out it wasn't
// Spend 3 days on it

class Solution {
public:
    bool dev(vector<double> cards){
        if(cards.size()==2){
            double value1 = cards[0]+cards[1];
            double value2 = cards[0]-cards[1];
            double value3 = cards[0]*cards[1];
            double value4 = (cards[1]==0 ? 1e9:cards[0]/cards[1]);

            double threshold = 0.000000001;

            bool conditionMet = false;
            if (fabs(value1 - 24) < threshold || fabs(value2 - 24) < threshold || fabs(value3 - 24) < threshold || fabs(value4 - 24) < threshold){
                return true;
            }
            return false;
        }
        if(cards.size()==3){
            int i=0;
            bool ans = false;
            while(i<2){
                double value1 = cards[i]+cards[i+1];
                double value2 = cards[i]-cards[i+1];
                double value3 = cards[i]*cards[i+1];
                double value4 = (cards[i+1]==0 ? 1e9:cards[i]/cards[i+1]);

                if((i+2)%3==2){
                ans = ans or dev({value1,cards[(i+2)%3]});
                ans = ans or dev({value2,cards[(i+2)%3]});
                ans = ans or dev({value3,cards[(i+2)%3]});
                ans = ans or dev({value4,cards[(i+2)%3]});
                }
                if((i+2)%3==0){
                ans = ans or dev({cards[(i+2)%3],value1});
                ans = ans or dev({cards[(i+2)%3],value2});
                ans = ans or dev({cards[(i+2)%3],value3});
                ans = ans or dev({cards[(i+2)%3],value4});
                }
                i++;
            }
            return ans;
        }
        if(cards.size()==4){
            int i=0;
            bool ans = false;
            while(i<3){
                double value1 = cards[i]+cards[i+1];
                double value2 = cards[i]-cards[i+1];
                double value3 = cards[i]*cards[i+1];
                double value4 = (cards[i+1]==0 ? 1e9:cards[i]/cards[i+1]);

                if(i==0){
                ans = ans or dev({value1,cards[(i+2)%4],cards[(i+3)%4],});
                ans = ans or dev({value2,cards[(i+2)%4],cards[(i+3)%4],});
                ans = ans or dev({value3,cards[(i+2)%4],cards[(i+3)%4],});
                ans = ans or dev({value4,cards[(i+2)%4],cards[(i+3)%4],});
                }
                if(i==1){
                ans = ans or dev({cards[(i+3)%4],value1,cards[(i+2)%4],});
                ans = ans or dev({cards[(i+3)%4],value2,cards[(i+2)%4],});
                ans = ans or dev({cards[(i+3)%4],value3,cards[(i+2)%4],});
                ans = ans or dev({cards[(i+3)%4],value4,cards[(i+2)%4],});
                }
                if(i==2){
                ans = ans or dev({cards[(i+2)%4],cards[(i+3)%4],value1});
                ans = ans or dev({cards[(i+2)%4],cards[(i+3)%4],value2});
                ans = ans or dev({cards[(i+2)%4],cards[(i+3)%4],value3});
                ans = ans or dev({cards[(i+2)%4],cards[(i+3)%4],value4});
                }
                i++;
            }
            return ans;
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> v;
        for(auto x:cards)   v.push_back(x);
        sort(v.begin(),v.end());
        do{
            if(dev(v))  return true;
        }while(next_permutation(v.begin(),v.end()));
        return false;
    }
};