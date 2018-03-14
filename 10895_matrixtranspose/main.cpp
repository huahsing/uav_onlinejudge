// 10895 Matrix Transpose
#include <bits/stdc++.h>

using namespace std;

bool compare_cols(tuple<int,int,int> t1, tuple<int,int,int> t2)
{
  return get<1>(t1) < get<1>(t2);
}

int main()
{
  // tuple<row, col, val>
  vector<vector<tuple<int,int,int>>> EL_list;
  vector<pair<int,int>> dimensions;
  int rows, cols, col_count, cur_col, cur_val, idx_cursor, matrix_cnt=0;
  
  cin >> rows;
  
  // assume input ends with zero when a new matrix is expected
  while(rows != 0)
  {
    cin >> cols;
    dimensions.push_back(make_pair(rows,cols));
    EL_list.push_back(vector<tuple<int,int,int>>());
    
    for(int i = 1; i <= rows; ++i)
    {
      cin >> col_count;
      
      for(int j = 0; j < col_count; ++j)
      {
        cin >> cur_col;
        EL_list[matrix_cnt].push_back(make_tuple(i, cur_col, 0));
      }

      for(int j = 0, idx_cursor = EL_list[matrix_cnt].size() - col_count; j < col_count; ++j, ++idx_cursor)
      {
        cin >> cur_val;
        get<2>(EL_list[matrix_cnt][idx_cursor]) = cur_val;
      }
    }
    
    ++matrix_cnt;
    cin >> rows;
  }
  
  for(int i = 0; i < EL_list.size(); ++i)
  {
    stable_sort(EL_list[i].begin(), EL_list[i].end(), compare_cols);
  }

  for(int i = 0; i < EL_list.size(); ++i)
  {
    cout << dimensions[i].second << " " << dimensions[i].first << endl;
    int edge_cnt = 0;
    for(int j = 1; j <= dimensions[i].second; ++j)
    {
      int count_nonzeroes = 0;
      string buf = "", buf2 = "";
      while(get<1>(EL_list[i][edge_cnt]) == j)
      {
        buf = buf + " " + to_string(get<0>(EL_list[i][edge_cnt]));
        if(buf2 == "") buf2 += to_string(get<2>(EL_list[i][edge_cnt]));
        else buf2 = buf2 + " " + to_string(get<2>(EL_list[i][edge_cnt]));
        ++edge_cnt;
        ++count_nonzeroes;
      }
      buf = to_string(count_nonzeroes) + buf;
      cout << buf << endl;
      cout << buf2 << endl;
    }
  }
  
  return 0;
}