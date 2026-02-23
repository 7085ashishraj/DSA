class BrowserHistory {
public:
    vector<string> history;
    int idx;
    BrowserHistory(string homepage) {
       history.push_back(homepage);
       idx = 0;
    }
    
    void visit(string url) {
        idx++;
        if(idx < history.size()){
            history.erase(history.begin()+idx, history.end());
        }
        history.push_back(url);
        
    }
    
    string back(int steps) {

        idx = max(0,idx - steps);
        return history[idx];   
    }
    
    string forward(int steps) {
        idx = min((int)history.size()-1, idx + steps);
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */