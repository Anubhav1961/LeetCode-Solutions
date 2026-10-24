class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        int a1 = stoi(aa.substr(0,2));
        int a2 = stoi(aa.substr(3,2));
        int b1 = stoi(al.substr(0,2));
        int b2 = stoi(al.substr(3,2));

        int c1 = stoi(ba.substr(0,2));
        int c2 = stoi(ba.substr(3,2));
        int d1 = stoi(bl.substr(0,2));
        int d2 = stoi(bl.substr(3,2));

        int start1 = a2, start2 = c2;
        int end1 = b2, end2 = d2;

        for(int i = 1; i < a1; i++) start1 += days[i];
        for(int i = 1; i < c1; i++) start2 += days[i];
        for(int i = 1; i < b1; i++) end1 += days[i];
        for(int i = 1; i < d1; i++) end2 += days[i];

        return max(0, min(end1, end2) - max(start1, start2) + 1);
    }
};