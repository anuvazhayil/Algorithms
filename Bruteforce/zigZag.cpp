int flag = 0, sum = 0, indx = 1;
class ZigzagIterator {
    vector<int>v1;
    vector<int>v2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        sum = v1.size() + v2.size();
    }

    int next() {
        int temp;
        if(!flag){
            if(this->v1.size() < indx){
                flag = !flag;
                temp = this->next();
            }
            else{
                temp = this->v1[indx-1];
                if(this->v2.size() < indx)
                    ++indx;
                else
                    flag = !flag;
            }
        }
        else{
            temp = this->v2[indx-1];
            if(this->v1.size() >= indx+1){
                flag = !flag;
            }
            ++indx;
        }

        return temp;
    }

    bool hasNext() {
        if(sum){
            --sum;
            return true;
        }
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
