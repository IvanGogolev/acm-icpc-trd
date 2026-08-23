struct Suff_arr{
  char LW = 3;
  int A = 256;
  string s0;
  string s1;
  vi arr;
  vi cost;
  vi rcost;
  vector<vector<pair<pair<int,int>,int > > > e1;
  vector<vector<pair<pair<int,int>,int > > > e2;
  vector<pair<pair<int,int>,int > > t;
  void Sort(vector<pair<pair<int,int>,int > >& t){
    fi(0,sz(t) - 1){
      e1[t[i].first.second].pb(t[i]);
    }
    fi(0,sz(e1) - 1){
      fx(e1[i]){
        e2[x.first.first].pb(x);
      }
      e1[i].clear();
    }
    t.clear();
    fi(0,sz(e2) - 1){
      fx(e2[i]){
        t.pb(x);
      }
      e2[i].clear();
    }
    
  }
  void init(string s){
    s0 = s;
    s1 = s;
    s1 += LW;
    fi(0,sz(s0) - 1){
      if( (sz(s1) & (sz(s1) - 1)) == 0)break;
      s1 += s0[i];
    }
    vvi e(A + 1);
    fi(0,sz(s1) -1){
      e[s1[i]].pb(i);
    }  
    fi(0,A){
      fx(e[i]){
        arr.pb(x);
      }
    }
    cost = vi(sz(arr));
    rcost = vi(sz(arr));
    fi(1,sz(arr) - 1){
      cost[i] = cost[i-1];
      if(s1[arr[i]] != s1[arr[i-1]]){
        cost[i]++;
      }
    }  
    int SIZ = 2;
    e1.resize(sz(arr));
    e2.resize(sz(arr));
    while(SIZ <= sz(arr)){
      fi(0,sz(arr) - 1){
        rcost[arr[i]] = cost[i];
      }  
      t.clear();
      fi(0,sz(arr) - 1){
        t.pb( mp( mp(rcost[arr[i]], rcost[ (arr[i] + SIZ / 2)%sz(arr)]), arr[i]) );
      }
      Sort(t);
      cost[0] = 0;
      arr[0] = t[0].second;
      fi(1,sz(arr) - 1){
        arr[i] = t[i].second;
        cost[i] = cost[i- 1];
        if(t[i].first != t[i - 1].first)cost[i]++;
      }
      SIZ *= 2;
    }
    
    vi arr2;
    fx(arr){
      if(x < sz(s0)){
        arr2.pb(x);
      }
    }
    arr = arr2;
  }
  vi LCP;
  void init_lcp(){
    vi rarr(sz(arr));
    fi(0,sz(arr) - 1){
      rarr[arr[i]] = i;
    }
    LCP = vi(sz(arr));
    int len = 0;
    fi(0,sz(arr) - 1){
      if(rarr[i] == sz(arr) - 1){
        len = 0;
        continue;
      }
      len = max(0,len - 1);
      int x = i;
      int y = arr[rarr[i] + 1];
      while(x + len < sz(s0) && y + len < sz(s0) && s0[x + len] == s0[y + len]){
        len++;
      }
      LCP[rarr[i]] = len;
      
    }
    
  }
};