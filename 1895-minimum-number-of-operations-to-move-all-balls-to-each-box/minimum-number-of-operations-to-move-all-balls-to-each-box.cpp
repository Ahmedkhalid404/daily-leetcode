class Solution {
public:
    vector<int> minOperations(string boxes) {
		int size = int(boxes.size());
        	vector< int > pref( size + 1 ) , suf( size + 1 );


		int ones = (boxes[0] == '1');
		for(int i = 1; i < size; i ++){
			pref[i] = pref[i - 1] + ones;
			ones += (boxes[i] == '1');
		}
		ones = (boxes[size - 1] == '1');
		for(int i = size - 2; ~i ; i--){
			suf[i] = suf[i + 1] + ones;
			ones += (boxes[i] == '1');
		}

		vector< int > ans( size );
		if( size > 1 ){
			ans[0] = suf[0];
			ans[size - 1] = pref[size - 1];
		}

		for(int i = 1; i < size - 1; i ++){
			ans[i] = pref[i] + suf[i];
		}

		return ans;

    }
};
