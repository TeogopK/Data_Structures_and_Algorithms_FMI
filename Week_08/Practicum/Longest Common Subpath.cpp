class Solution {
public:

    long long base = 1e5 + 7, mod = 1e11 + 7, pow[(int)1e5];

    bool f(int path_len, vector<vector<int>>& paths){
        // This function will return true if there is a subpath with length path_len, which appears in ALL rows in paths
        // We will use 2 unordered sets, one main, which we will pass down the rows and if it ever gets empty that means
        // that there is no intersection of hashes - so it is not possible to build a subpath, which is present in all rows.
        // The inner set will just get the hashes of each row and will be used to filter the main set (to get the intersection).
        unordered_set<long long> main_set;
        for(int i = 0; i < paths.size(); i++){
            if(paths[i].size() < path_len){
                return false;
            }
            unordered_set<long long> inner_set;
            long long hash=0;
            for(int j = 0; j < path_len; j++){
                hash = (hash + (((long long)(paths[i][j] + 1) * pow[path_len - 1 - j]) % mod)) % mod;
            }
            if(i == 0){
                main_set.insert(hash);
            }
            else{
                if(main_set.find(hash) != main_set.end()){
                    inner_set.insert(hash);
                }
            }
            for(int j = path_len; j < paths[i].size(); j++){
                hash = (hash + mod - (((long long)(paths[i][j - path_len] + 1) * pow[path_len - 1]) % mod)) % mod;
                hash = (long long)hash * base % mod;
                hash = (hash + paths[i][j] + 1) % mod;
                if(i == 0){
                    main_set.insert(hash);
                }
                else if(main_set.find(hash) != main_set.end()){
                    inner_set.insert(hash);
                }
            }
            if(i > 0){
                // Pass the object down the rows, if it ever gets empty that means we
                // can't have a path that long
                main_set = std::move(inner_set);
            }
            if(main_set.size() == 0){
                return false;
            }
        }
        return main_set.size() > 0 ? true : false;
    }

    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        // We will do a binary search solution, where we will have a function f, which will say whether there is or
        // there isn't a subpath of length {mid} that is present in all paths. If there isn't then we are sure there we will not
        // be a path of length {mid + 1} or in fact any number >= mid. Double hashing may also be required to avoid collisions,
        // but if we choose the base and mod wisely, we can avoid doing a double hash.
        int left = 1, right = 1e5;

        pow[0] = 1;
        for(int i = 1; i < right; i++) pow[i] = (long long)base * pow[i - 1] % mod;

        while(left <= right){
            int mid = (left + right) / 2;
            if(f(mid, paths)){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }
};
