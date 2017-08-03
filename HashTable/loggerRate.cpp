class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int>print_time;
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if((print_time.count(message) == 0) || ((timestamp - print_time[message]) >= 10)){
            print_time[message] = timestamp;
            return true;
        }
            return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
