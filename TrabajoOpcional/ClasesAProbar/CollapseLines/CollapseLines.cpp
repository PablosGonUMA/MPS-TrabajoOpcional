#include <iostream>
#include <stdexcept>
#include <string>

namespace CollapseLines {
    using namespace std;

    class CollapseLines {

        public static string collapseNewLines(string arg) {

            char last = arg.at(0);
            string buffer = "";

            for (int index = 0; index < arg.size(); index++) {
                char ch = arg.at(index);
                if (ch != '\n' || last != '\n') {
                    buffer = buffer + ch;
                    last = ch;
                }
            }

            return buffer;
        }
    }
}
