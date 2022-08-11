// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    int zz;
    Song(const std::wstring &artist_, const std::wstring &title_) : artist{artist_}, title{title_} {}

    friend wostream& operator<<(wostream &os, Song &song) {
        os << song.artist << "," << song.title << endl;
        return os;
    }
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring &date_,
        const std::wstring &location_,
        const std::wstring &subject_) : date{date_}, location{location_}, subject{subject_} {}
};

using namespace std;

void func(shared_ptr<Song> s) {
    wcout<< *(s.get());
    cout << s.use_count();
    cout << endl;
}

int main()
{
    // vector<shared_ptr<Song>> v{
    //     make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
    //     make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
    //     make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")};

    // vector<shared_ptr<Song>> v2;
    // remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
    //                { return s->artist.compare(L"Bob Dylan") == 0; });

    //  v[1]->artist = L"new";

    // for (const auto &s : v2)
    // {
    //     wcout << s->artist << L":" << s->title << endl;
    // }

    //  for (const auto &s : v)
    // {
    //     wcout << s->artist << L":" << s->title << endl;
    // }
    shared_ptr<Song> s1 = std::make_shared<Song>(L"artist1",L"title1");
    cout<<s1.use_count()<<endl;

    shared_ptr<Song> s2(s1);
    cout<<s1.use_count()<<endl;

    func(std::move(s1));

    wcout<<s1.get()->artist<<endl;
   
    cout<<s1.use_count()<<endl;

    shared_ptr<Song> s3 = s1;
    cout<<s1.use_count()<<endl;
    s1.reset();
    cout<<s1.use_count()<<endl;
    cout<<s3.use_count()<<endl;
}
