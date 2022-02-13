using namespace std;

int minimumWaitingTime(vector<int> queries) {
	sort(queries.begin(), queries.end());
	int len = queries.size();
	int duration = 0;
	int left = 0;
	for (int i = 0; i < len; ++i)
	{
		duration += left;
		left += queries[i];
	}
	return duration;
}
