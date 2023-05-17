#include <iostream>
#include <stdexcept>
#include <string>
#include <C:\Users\Dani\OneDrive\Documentos\Uni\3o\Mantenimiento\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\CollapseLines\CollapseLines.h>

using namespace std;

string CollapseLines::collapseNewLines(string arg) {

    char last = arg.at(0);
    string buffer = "";

    for (unsigned index = 0; index < arg.size(); index++) {
        char ch = arg.at(index);
        if (ch != '\n' || last != '\n') {
            buffer = buffer + ch;
            last = ch;
        }
    }

    return buffer;
}
  

