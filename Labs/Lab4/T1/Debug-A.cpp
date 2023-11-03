#include<iostream>
#include<string>
#include <utility>

using namespace std;

//class Painting {
//protected:
//    string title;
//    string artist;
//    int value{};
//
//public:
//    Painting();
//    // will not work without an empty constructor
//
//    explicit Painting(string, string = " ");
//
//    void showPainting();
//
//    void setData();
//
//    string getArtist();
//
//    string getTitle();
//};
//
//Painting::Painting() {
//    title = "";
//    artist = "";
//}
//
//class FamousPainting : public Painting {
//public:
//    FamousPainting(string, string);
//};
//
//Painting::Painting(string name, string painter) : title(std::move(name)), artist(std::move(painter)), value(400) {}
//
//void Painting::setData() {
//    cout << "Enter painting's title: ";
//    cin.ignore();
//
//    getline(cin, title);
//
//    if (title == "EXIT" || title == "exit") {
//        cout << "Program is closing" << endl;
//        exit(0);
//    }
//
//    cout << "Enter artist: ";
//    getline(cin, artist);
//
//    if (artist == "EXIT" || artist == "exit") {
//        cout << "Program is closing" << endl;
//        exit(0);
//    }
//
//    value = 400;
//    // getting info from the user. uses an if statement to close program if the user writes exit
//    // using get line as if u use cin >> and there is a whitespace in the input it will not take it
//}
//
//void Painting::showPainting() {
//    cout << title << " by artist: " << artist << " is valued at $" << value << endl;
//}
//
//string Painting::getArtist() {
//    return artist;
//}
//
//string Painting::getTitle() {
//    return title;
//}
//
//FamousPainting::FamousPainting(string name, string painter) :
//        Painting(std::move(name), std::move(painter)) {
//    value = 25000;
//}
//
//bool isPaintingFamous(Painting p) {
//    bool isFamous = false;
//    const int NUM = 4;
//    string artists[NUM] = {"Degas", "Monet", "Picasso", "Rembrandt"};
//    string artist = p.getArtist();
//    for (const auto &i: artists) {
//        if (artist == i) {
//            isFamous = true;
//            break;
//        }
//    }
//    return isFamous;
//    /*
//     this method takes the artist name from the object and compares it with an inputted string
//     if the string is true then it will return true and break the loop
//     */
//}
//
//int main() {
//    cout << "---------------------------Program initiated -----------------------------" << endl;
//    cout << "Type 'EXIT' or 'exit' to close program!!" << endl << endl;
//    const int NUM = 6;
//
//    Painting pictures[NUM];
//    int x;
//    for (x = 0; x < NUM; ++x) {
//
//        pictures[x].setData();
//        // setting the details of the objects in the array via for loop
//
//        if (isPaintingFamous(pictures[x])) {
//            FamousPainting tempF(pictures[x].getTitle(), pictures[x].getArtist());
//            pictures[x] = tempF;
//            /*
//             running a bool method to check if the painting is done by a famous author or not,
//             if it is then it will change from 400 to 25000
//            */
//        }
//    }
//
//    for (auto &picture: pictures) {
//        picture.showPainting();
//    }
//    // for loop to show the information at the end of the program
//
//    return 0;
//    cout << "---------------------------Program terminated-----------------------------" << endl << endl;
//}

class Painting
{
protected:
    string title;
    string artist;
    int value;

public:
    Painting() : title(), artist(), value() {}
    Painting(string t, string a) : title(std::move(t)), artist(std::move(a)), value(0) {}
    void showPainting();
    void setData();
    string getArtist();
    string getTitle();
};

//Painting::Painting(string name, painter)
//{
//    name = title;
//    artist = painter;
//    value = 400;
//}
void Painting::setData()
{
    cout<<"Enter painting's title ";
    cin>>title;
    cout<<"Enter artist ";
    cin>>artist;
    value = 400;
}
void Painting::showPainting()
{
    cout<<title <<artist<<" value $400";
}
string Painting::getArtist()
{
    return artist;
}
string Painting::getTitle()
{
    return title;
}

class FamousPainting : public Painting
{
public:
FamousPainting(string, string);
};

FamousPainting::FamousPainting(string name, string painter) :
        Painting(std::move(name), std::move(painter))
{
    value = 2500;
}
bool isPaintingFamous(Painting p)
{
    bool isFamous = true;
    const int NUM = 4;
    string artists[NUM] = {"Degas","Monet","Picasso","Rembrandt"};
    int x;
    for(x = 0; x < NUM; ++x)
        if(p.getArtist() == artists[x])
            isFamous = false;
    return isFamous;
}
int main()
{
    const int NUM = 6;
    Painting pictures[NUM];
    int x;
    for(x = 0; x<NUM; ++x)
    {

        pictures[x].setData();

        if(isPaintingFamous(pictures[x]))
        {
            FamousPainting tempF(pictures[x].getTitle(), pictures[x].getArtist());
            pictures[x] = tempF;

        }

    }
    for(x = 0; x< NUM; x--)
        pictures->showPainting();
}
