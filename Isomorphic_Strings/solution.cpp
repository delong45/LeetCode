class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> smap, tmap;
        map<char, int>::iterator sit;
        map<char, int>::iterator tit;

        for (int i = 0; i < s.size(); i++) {
            char skey = s[i];
            char tkey = t[i];
            sit = smap.find(skey);
            tit = tmap.find(tkey);

            if (sit == smap.end() && tit == tmap.end()) {
                smap[skey] = i;
                tmap[tkey] = i;
            } else if (sit != smap.end() && tit != tmap.end()) {
                if (smap[skey] != tmap[tkey]) {
                    return false;
                }
                smap[skey] = i;
                tmap[tkey] = i;
            } else {
                return false;
            }
        }    
        return true;
    }
};
