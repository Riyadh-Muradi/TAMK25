#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string nimi;
    string kuvaus;

    cout << "Nimesi: ";
    getline(cin, nimi);
    cout << "Kuvaile itseäsi: ";
    getline(cin, kuvaus);

    ofstream sivu;
    sivu.open("index.html");

    if (sivu)
    {
        sivu << "<html>" << endl;
        sivu << "<head>" << endl;
        sivu << "</head>" << endl;
        sivu << "<body>" << endl;
        sivu << "    <center>" << endl;
        sivu << "        <h1>" << nimi << "</h1>" << endl;
        sivu << "    </center>" << endl;
        sivu << "    <hr />" << endl;
        sivu << "    " << kuvaus << endl;
        sivu << "    <hr />" << endl;
        sivu << "</body>" << endl;
        sivu << "</html>" << endl;

        sivu.close();
        cout << "Luotu html sivu onnistu" << endl;
    }
    else
    {
        cout << "tiedoston luomine ei onnistunu" << endl;
    }

    return 0;
}