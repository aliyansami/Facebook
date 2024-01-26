#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
#include<stdlib.h>


class Post;
class Facebook;
class User;
class Page;


using namespace std;
class Helper {
public:

    //Gives the string's lenght
    static int StringLenght(const char* mystr)
    {
        int counter = 0;
        if (mystr)
        {
            for (int i = 0; mystr[i] != '\0'; i++)
            {
                counter++;
            }
        }
        return counter;
    }

    //Helps to get the name of teh student
    static char* GetStringFromBuffer(char* buffer)
    {
        char* n = 0;
        int strLen = StringLenght(buffer);
        char* str = 0;

        if (strLen > 0)
        {
            n = new char[strLen + 1];
            char* tempDest = n;

            for (char* tempSrc = buffer; *tempSrc != '\0'; tempSrc++, tempDest++)
            {
                *tempDest = *tempSrc;
            }
            *tempDest = '\0';
        }
        return n;
    }

    //Concatenates the first and last name
    static void StringConcatenante1(char* string1, char* string2)
    {

        int sizestring1 = 0;
        int sizestring2 = 0;

        sizestring1 = StringLenght(string1);
        sizestring2 = StringLenght(string2);

        int totalsize = sizestring1 + sizestring2;

        char* Concatentedstring = new char[totalsize + 1];

        int x = 0;

        for (int i = 0; i < sizestring1; i++)
        {
            Concatentedstring[x] = string1[i];
            x++;
        }

        Concatentedstring[x] = ' ';
        x++;

        for (int i = 0; i < sizestring2; i++)
        {
            Concatentedstring[x] = string2[i];
            x++;
        }
        Concatentedstring[x] = '\0';


        string1 = new char[totalsize + 1];
        int y = 0;
        for (int i = 0; i < totalsize + 1; i++)
        {
            string1[y] = Concatentedstring[i];
            y++;
        }

        string1[y] = '\0';

    }

    //compares, wheather the two strings are equal
    static int strgcmp(const char str[], const char str1[])
    {
        int counter = 0;
        int size = StringLenght(str);
        int size1 = StringLenght(str1);

        if (size1 == size)
        {
            for (int i = 0; i < size; i++)
            {
                if (str[i] == str1[i])
                {
                    counter++;
                }
            }

            if (counter == size)
            {
                return 1;
            }
        }

        return 0;
    }

    //Copies the two strings
    static char* strg_cpy(char* str, const char* str1)
    {
        int i = 0;
        int lenght = StringLenght(str1);
        str = new char[lenght + 1];
        if (str1 != 0)
        {
            for (; i < lenght; i++)
            {
                str[i] = str1[i];

            }
            str[i] = '\0';
        }
        return str;
    }


};

class Post;

class User;
class Page;

class Base  //class Base
{
private:
    char* ID;

public:

    char* get_ID()
    {
        return ID;
    }
    Base()
    {
        ID = NULL;
    }
   virtual ~Base()
    {
        if (ID)
            delete[] ID;
    }
    void LoadId(ifstream& fin)
    {
        char buffer[100];
        fin >> buffer;
        ID = Helper::GetStringFromBuffer(buffer);           //storing the ID
    }

    virtual void set_id(const char* str) {}

    virtual void  AddposttoTimeline(Post ptr[], int index) = 0;  //virtual function for adding the null to Timeline

    virtual void  AddposttoTimelinei(Post ptr[]) = 0;         //virtual function to add post to timeline

    virtual void AllocateMemoryforTimeline() = 0;   //virtual function for alloacating tne memory of the timeline double pointer

    virtual void Showrecebpostbyobj() {};

    virtual char* getfname() { return ID; }     //virtual dunction to get first name
    virtual char* getlname() { return ID; }     //virtual fucntion get last name
    virtual char* get_title() { return ID; }    //virtual function to get title of the page

    virtual char* Get__Id() { return ID; }  //To get id of the obj

    virtual void Get_info() {} //To get the info of the obj

    virtual void Print_obj() {}
};



class Date      //class Date
{
private:
    int day;
    int month;
    int year;
    static Date currdate;
public:

    Date(int d = 0, int m = 0, int y = 0)
    {
        day = d;
        month = m;
        year = y;
    }

    Date operator=(const Date rhs)
    {
        if (&rhs != this)
        {
            day = rhs.day;
            month = rhs.month;
            year = rhs.year;
        }
        return *this;
    }


    static void Set_currdate(int d, int m, int y);

    static Date get_currdate()
    {
        return currdate;
    }

    void DataFromfile(ifstream& in)     //To get Date from file
    {
        in >> day;
        in >> month;
        in >> year;
        in.ignore();
    }

    void SetDate(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void get_currentdate()
    {
        cout << currdate.get_day() << "/" << currdate.get_month() << "/" << currdate.get_year();
        cout << "\n";
    }
    static Date get_curr_date()     //Setting the current date as static thus can be used in the project at all time
    {
        return currdate;
    }

    void GetDate()      //To view the date in the format     
    {
        cout << day << "/" << month << "/" << year;
    }

    bool chkda(Date ptr)    //cheaking the post date with the current date
    {
        if (ptr.get_day() == this->get_day() || ptr.get_day() - 1 == this->get_day() && ptr.get_month() == this->get_month())
        {
            return 1;
        }
        return 0;
    }

    bool chkda1(Date ptr)    //cheaking the post date with the current date
    {
        if (ptr.get_day() == this->get_day() || ptr.get_day() == this->get_day() && ptr.get_month() == this->get_month())
        {
            return 1;
        }
        return 0;
    }

    static void get_todaydate();

    int chktime(Date ptr)
    {
        return ptr.get_year() - this->get_year();
    }

    int calculatingyears()
    {
        return  currdate.get_year()-this->year;
    }

    //Getters
    int get_day()
    {
        return day;
    }
    int get_month()
    {
        return month;
    }
    int get_year()
    {
        return year;
    }

};

Date Date::currdate(0, 0, 0);

void Date::Set_currdate(int d, int m, int y)
{

    Date::currdate.SetDate(d, m, y);

    cout << d << "/" << m << "/" << y << "\n";

}

void Date::get_todaydate()
{
    cout << Date::currdate.get_day() << "/" << Date::currdate.get_month() << "/" << Date::currdate.get_year() << "\n";
}

class Activity      //Class of Activity
{
private:
    int type;
    char* value;

public:

    Activity()      //Constructor
    {
        type = 0;
        value = NULL;
    }

    ~Activity()
    {   
        if(value)
        delete[] value;
        value = nullptr;
    }

    void LoadDataFromFile(ifstream& in)     //Read From file
    {
        in >> type;
        in.ignore();

        char buffer[100];
        in.getline(buffer, 100, '\t');

        value = Helper::GetStringFromBuffer(buffer);
    }

    void get_type()      //getting the type of the activity
    {
        if (type == 1)
        {
            cout << " feeling ";
        }
        if (type == 2)
        {
            cout << " thinking about ";
        }
        if (type == 3)
        {
            cout << " Making ";
        }
        if (type == 4)
        {
            cout << " Celebrating ";
        }
    }
    char* get_v()      //getting the value of the acivity
    {
        return value;
    }
};


class Comment       //class comment
{
private:
    char* text;
    Base* commentby;
    char* ID;

public:

    Comment()       //constructor
    {
        text = NULL;
        commentby = NULL;
        ID = NULL;
    }

    ~Comment()
    {
        if(text)
            delete[] text;
        if(ID)
            delete[] ID;

        commentby = NULL;
    }

    void LoadIDFromFile(ifstream& in)      //Read from file
    {
        char temp[20];
        in >> temp;

        ID = Helper::GetStringFromBuffer(temp);
    }

    void Loadtxt(ifstream& in)
    {
        char temp[100];
        in.getline(temp, 100);

        text = Helper::GetStringFromBuffer(temp);
    }

    void Add_obj_that_commented(Base* ptr)      //to set the obj that commented
    {
        commentby = ptr;
    }

    char* get_txt()     //getter for text of the comment
    {
        return text;
    }

    Base* get_person()      //getter for obj commented
    {
        return commentby;
    }

    void storecomment(const char* str)      //storring the text comment at runtime
    {
        text = Helper::strg_cpy(text, str);
    }


};

class Memory;

class Post      //Class of Post
{
private:
    char* text;
    char* ID;
    Base* sharedby;
    Base** LikedBy;
    Activity* acti;
    Date* sharedDate;
    Comment** comments;
    Memory* memories;
    char* addtxtformrmory;


public:

    Post()      //constructor      
    {
        text = NULL;
        sharedby = NULL;
        acti = NULL;
        LikedBy = new Base * [10];
        for (int i = 0; i < 10; i++)
        {
            LikedBy[i] = NULL;
        }
        sharedDate = NULL;
        comments = new Comment * [10];
        for (int i = 0; i < 10; i++)
        {
            comments[i] = NULL;
        }

    }

    ~Post()
    {
       
        if(text)
            delete[] text;
        if(ID)
            delete[] ID;
        if (LikedBy)
            delete LikedBy;
        if(acti)
            delete acti;

        sharedDate = NULL;
        sharedby = NULL;
        if (comments)
        {
            for (int i = 0; comments[i]!=NULL; i++)
            {
                if (comments[i])
                {
                    delete comments[i];
                }
            }
            delete[] comments;
            comments = NULL;
        }

        memories = NULL;
    }

    bool cheackformemory()
    {
        if (this->get_date()->chkda1(Date::get_currdate()) == 1)
        {
            return 1;
        }
        return 0;
    }

    void calculatetime()
    {
        cout << this->get_date()->calculatingyears();
    }

    bool checkdateofthepost()
    {
        if (this->get_date()->chkda(Date::get_currdate()) == 1)
        {
            return 1;
        }
        return 0;
    }

    void Print()
    {
        
        cout << "----";
        sharedby->Get_info();
            
            if (this->get_act() != NULL)
            {
                cout << " is ";
                this->get_act()->get_type();
                cout << " " << this->get_act()->get_v();
                cout << "\n";
            }
            else
            {
                cout << " shared: ";
            }
            if (this->get_addtxtformrm() != NULL)
            {
                cout << "~~~" << this->get_sharedBy()->getfname() << " " << this->get_sharedBy()->getlname() << "shared a memory~~~...";                cout << setw(10);
                cout << setw(10);
                Date::get_todaydate();
                cout << "\"" << this->get_addtxtformrm() << "\"" << "\n";
            }

            cout << "\"" << this->get_txt() << "\"" << "............";
            this->get_date()->GetDate();
            viewcomments(this);
            cout << "\n" << "\n";
        
    }

    void set_txt(const char* ptr)
    {
        text = Helper::strg_cpy(text, ptr);
    }

    void set_shareddate(Date* ptr)
    {
        sharedDate = ptr;
    }

    void set_comment(Comment** pt)
    {
        comments = pt;
    }

    void set_activity(Activity* ptr)
    {
        acti = ptr;
    }

    Comment** get_allcomments()
    {
        return comments;
    }

    void set_id(const char* ptr)
    {
        ID = Helper::strg_cpy(ID, ptr);
    }

    Post* operator=(const Post rhs)
    {
        if (this != &rhs)
        {
            ID = Helper::strg_cpy(ID, rhs.ID);
            text = Helper::strg_cpy(text, rhs.text);
            comments = rhs.comments;
            addtxtformrmory = Helper::strg_cpy(addtxtformrmory, rhs.addtxtformrmory);
        }
        return this;
    }

    void LoadFromFile(ifstream& fin)        //Read from file
    {
        int isActivity = 0;     //Storring the type of the post

        fin >> isActivity;
        char temp[30];

        fin >> temp;
        ID = Helper::GetStringFromBuffer(temp);         //storing the ID


        sharedDate = new Date;          //Reading date from the file
        sharedDate->DataFromfile(fin);


        char buffer[200];              //reading text of the post from the file
        fin.getline(buffer, 200);

        while (buffer[0] == '\t')
        {
            fin.getline(buffer, 200, '\t');
        }

       text = Helper::GetStringFromBuffer(buffer);
        //text = Helper::strg_cpy(text, buffer);

        if (isActivity == 2)               //if the post has an activity
        {
            acti = new Activity;
            acti->LoadDataFromFile(fin);
        }
        else
        {
            acti = new Activity;
            acti = NULL;
        }
    }

    void Addcomment(Comment* ptr)       //adding the ptr of comment in the 2D pointer 'comments'
    {
        for (int i = 0; ; i++)
        {
            if (comments[i] == NULL)
            {
                comments[i] = ptr;
                i++;
                comments[i] = NULL;
                break;
            }
        }
    }

    void Allocate_memory_for_comment()       //Allocating memory for 'comments'
    {
        comments = new Comment * [50];
    }


    void Set_sharedby(Base* ptr)    //setting the obj that shared the post
    {
        sharedby = ptr;
    }

    void Set_LikedBy(Base* ptr, int index)    //setting the obj that liked the post
    {
        /*if (index)
        {
            LikedBy = new Base * [10];
            LikedBy[index] = ptr;
        }*/
        LikedBy[index] = ptr;
    }

    void memory_for_obj_that_liked_post()      //Allocating memory for **Likedby
    {
        LikedBy = new Base * [100];
    }

    //getters
    char* get_ID()
    {
        return ID;
    }

    char* get_txt()
    {
        return text;
    }

    Date* get_date()
    {
        return sharedDate;
    }

    Base* get_sharedBy()
    {
        return sharedby;
    }

    Comment* get_comm(int i)
    {
        return comments[i];
    }

    Activity* get_act()
    {
        return acti;
    }

    char* get_addtxtformrm()
    {
        return addtxtformrmory;
    }

    void Likepost(Base* ptr)  //To like a ceratin post at runtime
    {
        cout << "Command: " << "LikedPost(";
        cout << this->get_ID() << ")" << "\n";

        for (int i = 0; ; i++)
        {
            if (LikedBy[i] == NULL)
            {
                LikedBy[i] = ptr;
                i++;
                LikedBy[i] = NULL;
                break;
            }
        }
    }

    void viewlikedby()  //To view the objs that liked the post
    {
        cout << "\n";
        cout << "-----------------------------------------------------------------" << "\n";
        cout << "Command: " << setw(10) << "ViewLikedList(";
        cout << this->get_ID() << ")" << "\n";
        cout << "\n";

        for (int i = 0; LikedBy[i] != NULL; i++)
        { 
           /* cout << LikedBy[i]->Get__Id() << "-";
            LikedBy[i]->Get_info();*/
            LikedBy[i]->Print_obj();
        }
        cout << "\n";
        cout << "-----------------------------------------------------------------" << "\n";
    }


    void viewcomments(Post ptr[])       //To view the comments on the post
    {
        int i = 0;
        while (ptr->get_comm(i) != NULL)
        {
            cout << "\n";
            Base* n = ptr->get_comm(i)->get_person();

            n->Get_info();
            cout << " wrote: ";

            cout << ptr->get_comm(i)->get_txt();

            i++;
        }
    }
    void viewpost()     //To view posts
    {
        cout << "-----------------------------------------------------------------" << "\n";
        cout << "Command: " << setw(10) << "ViewPost" << "\n";
        Base* ptr = this->sharedby;

        cout << "---";
        ptr->Get_info();

        if (this->get_act() != NULL)
        {
            cout << " is ";
            this->get_act()->get_type();
            cout << " " << this->get_act()->get_v();
            cout << "\n";
        }
        cout << "\"" << this->get_txt() << "\"" << "............";
        this->get_date()->GetDate();
        viewcomments(this);
        cout << "\n" << "\n";

        cout << "-----------------------------------------------------------------" << "\n";

    }

    void addcomment(Base* ptr, const char* str)      //To add comment at runtime
    {
        cout << "Command: " << "AddComment(";
        cout << this->get_ID() << ", ";
        cout << str << ")" << "\n";

        for (int i = 0; ; i++)
        {
            if (this->get_comm(i) == NULL)       //storring the ptr of the comment
            {
                comments[i] = new Comment;

                comments[i]->Add_obj_that_commented(ptr);
                i++;
                ptr = NULL;
                comments[i] = NULL;
                break;
            }
        }
        for (int i = 0; ; i++)
        {
            if (comments[i]->get_txt() == NULL)     //storring the text of the comment
            {
                comments[i]->storecomment(str);
                i++;
                str = NULL;
                comments[i] = NULL;
                break;
            }
        }

    }

    void storeextratxtformemory(const char str[])
    {
        addtxtformrmory = Helper::strg_cpy(addtxtformrmory, str);
    }

};


class Memory : public Post
{
private:
    Post* orignalpost;
    //Post** newpost;

public:
    Memory()
    {
        orignalpost = NULL;
       // newpost = NULL;
    }


    void addmemorytonewpostarray(Post** Memoryarray, Post* post)
    {
        for (int i = 0; Memoryarray[i] != NULL; i++)
        {
            Memoryarray[i] = new Post;
            Memoryarray[i]->set_id(post->get_ID());
            Memoryarray[i]->Set_sharedby(post->get_sharedBy());
            Memoryarray[i]->set_txt(post->get_txt());
            Memoryarray[i]->set_shareddate(post->get_date());
            Memoryarray[i]->set_activity(post->get_act());
            Memoryarray[i]->set_comment(post->get_allcomments());
            //Memoryarray[i] = post;
            Memoryarray[i + 1] = NULL;
        }
    }

    void Allocatememoryfornewpostarray()
    {
        //getters
        //newpost = new Post * [10];
        /*for (int i = 0; i < 10; i++)
        {

            newpost[i] = NULL;
        }*/
    }


    void  chkmemory(Post* ptr)
    {
        orignalpost = ptr;

        if (orignalpost->get_date()->chkda1(Date::get_curr_date()) == 1)
        {

            //addmemorytonewpostarray(newpost, orignalpost);
            cout << "Command: " << setw(10) << "ViewMemory" << "\n";

            cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago." << "\n";
            cout << "On this Day" << "\n";

            cout << orignalpost->get_date()->chktime(Date::get_curr_date()) << " Years Ago" << "\n";

            orignalpost->viewpost();

        }

    }

   Post* Get_memory(int i)
    {
        return orignalpost;
    }

    ~Memory()
    {
        orignalpost = NULL;
    }
};

class Facebook;

class Page : public Base          //class Page
{
private:

    char* Title;
    Post** Timeline;
    int totalpostintimleine;

public:

    Page()     //Constructor
    {
        Title = nullptr;

        Timeline = new Post * [10];

        for (int i = 0; i < 10; i++)
        {
            Timeline[i] = NULL;
        }
    }

    void Get_info()     //virtual function to get the title of the page
    {
        cout << this->get_title();
    }

    void Print()
    {
        cout << this->get_ID() << "-";
        cout << this->get_title();
    }

    void ReadFromPage(ifstream& in)     //Read from file
    {
        LoadId(in);      // Getting the ID
        in.ignore();
        char buffer[100];
        in.getline(buffer, 100);
        Title = Helper::GetStringFromBuffer(buffer);    //Getting the Title    
    }

    void commd()    //command
    {
        cout << "-----------------------------------------------------------------" << "\n";

        cout << "Command: ";
        cout << setw(10) << "View page(" << this->Base::get_ID() << ")" << "\n";
    }

    void viewcomments(Post ptr[])   //To view comments on the post
    {
        int i = 0;
        while (ptr->get_comm(i) != NULL)
        {
            cout << "\n";
            Base* n = ptr->get_comm(i)->get_person();

            n->Get_info();
            cout << " wrote: ";

            cout << ptr->get_comm(i)->get_txt();

            i++;
        }
    }


    bool checkdateofthepost(Post* ptr)
    {
        if (ptr->get_date()->chkda(Date::get_currdate()) == 1)
        {
            return 1;
        }
        return 0;
    }

    void Print_obj() 
    {
        this->get_ID();
        cout<<"-"<< this->Title;
    }

    void Showrecebpostbyobj()
    {
        for (int i = 0; Timeline[i] != NULL; i++)
        {
            if(Timeline[i]->checkdateofthepost()==1)
           
             Timeline[i]->Print();
        }
    }


    void viewpage()     //To view the page
    {
        this->commd();
        cout << this->Title << "\n" << "\n";

        int i = 0;

        while (this->Timeline[i] != NULL)
        {
            cout << "----" << this->Title;
            cout << " is ";
            if (Timeline[i]->get_act() != NULL)
            {

                Timeline[i]->get_act()->get_type();
                cout << " " << Timeline[i]->get_act()->get_v();
                cout << "\n";
            }


            cout << "\"" << Timeline[i]->get_txt() << "\"" << "............";
            Timeline[i]->get_date()->GetDate();
            viewcomments(Timeline[i]);
            cout << "\n" << "\n";
            i++;
        }
        cout << "-----------------------------------------------------------------" << "\n";
        cout << "\n";
    }


    void viewpagebytime()       //to view the posts by the page according to the current date
    {
        int i = 0;

        while (this->Timeline[i] != NULL)
        {
            if (Timeline[i]->get_date()->chkda(Date::get_curr_date()) == 1)
            {
                cout << "----" << this->Title;
                cout << " is ";
                if (Timeline[i]->get_act() != NULL)
                {

                    Timeline[i]->get_act()->get_type();
                    cout << " " << Timeline[i]->get_act()->get_v();
                    cout << "\n";
                }


                cout << "\"" << Timeline[i]->get_txt() << "\"" << "............";
                Timeline[i]->get_date()->GetDate();
                viewcomments(Timeline[i]);
                cout << "\n" << "\n";

            }
            i++;
        }
    }

    void AllocateMemoryforTimeline()    //Polymorphism
    {
        Timeline = new Post * [100];
    }

    void AddposttoTimeline(Post ptr[], int index)    //Polymorphism
    {
        Timeline[index] = ptr;
    }

    void AddposttoTimelinei(Post ptr[])     //Add post to timeline, (polymorphism)
    {

        for (int i = 0; ; i++)
        {
            if (Timeline[i] == NULL)
            {
                Timeline[i] = ptr;
                totalpostintimleine++;
                i++;
                Timeline[i] = NULL;
                break;
            }
        }
    }

    //Getters
    char* get_id()
    {
        return Base::get_ID();
    }

    char* Get__ID()
    {
        return Base::get_ID();
    }

    char* get_title()
    {
        return Title;
    }

    //Destructor
   ~Page()
    {
        if (Title)
            delete[] Title;

        if (Timeline)
        {
            for (int i = 0; i < totalpostintimleine; i++)
            {
                if (Timeline[i])
                {
                    delete Timeline[i];
                }
            }
            delete[] Timeline;
            Timeline = nullptr;
        }
    }

};


class Facebook;

class User : public Base      //class Users
{
private:

    char* FirstName;
    char* LastName;
    User** FriendList;
    Page** LikedPages;
    Post** Timeline;
    Memory memor;

public:

    User()       //constructor
    {

        FirstName = nullptr;
        LastName = nullptr;
        FriendList = nullptr;
        LikedPages = nullptr;
        Timeline = new Post * [10];

        for (int i = 0; i < 10; i++)
        {
            Timeline[i] = NULL;
        }
    }

    void Showrecebpostbyobj()
    {
        for (int i = 0; Timeline[i] != NULL; i++)
        {
            if (Timeline[i]->checkdateofthepost() == 1)

                Timeline[i]->Print();
        }
    }

    void Print_obj()
    {
        this->Get__ID();
        cout << "-" << this->getfname()<<" "<<this->getlname();

    }

    char* Get__ID()     //getter
    {
        return Base::get_ID();
    }

    void Get_info()    //polymorphism
    {
        cout << this->getfname() << " " << this->getlname();
    }

    char* get_id()    //to get the id
    {
        return Base::get_ID();
    }

    void ReadfromUser(ifstream& in)
    {
        char tempn[30];     //creating a buffer to store info temporarily
        LoadId(in);

        in >> tempn;    //reading firstname of the user
        FirstName = Helper::GetStringFromBuffer(tempn);
        in >> tempn;    //reading the lastname of user
        LastName = Helper::GetStringFromBuffer(tempn);

    }

    void Allocate_memeorypgs()       //allocate the memory to store the pointers of liked pages
    {
        LikedPages = new Page * [10];
    }

    void Allocate_memoryfrn()     //allocate memory to store the pointers of Friends
    {
        FriendList = new User * [10];
    }

    void set_likedpages(Page* ptr, int index)    //placing the pointer of the liked page in the **LikedPage
    {
        LikedPages[index] = ptr;
    }

    void set_frndlist(User* ptr, int index)     //placing the pointer of the friend in the **FriendList
    {
        FriendList[index] = ptr;
    }

    void AddposttoTimeline(Post ptr[], int index)     //Polymorphism
    {
        Timeline[index] = ptr;
    }

    void AddposttoTimelinei(Post ptr[])     //Adding post to timeline
    {
        for (int i = 0; ; i++)
        {
            if (Timeline[i] == NULL)
            {
                Timeline[i] = ptr;
                i++;
                Timeline[i] = NULL;
                break;
            }
        }
    }

    void AllocateMemoryforTimeline()    //Polymorphism
    {
        Timeline = new Post * [100];
    }

    //getters
    char* getfname()
    {
        return FirstName;
    }

    char* getlname()
    {
        return LastName;
    }

    void Print()
    {
        cout << this->Base::get_ID() << "-";
        cout << this->FirstName << " ";
        cout << this->LastName << " ";

    }

    void viewfriendlist()    //Used to view friend list of friends
    {
        cout << "Command: ";
        cout << setw(10) << "View Friend List" << "\n";
        cout << "-----------------------------------------------------------------" << "\n";

        cout << this->FirstName << " " << this->LastName << "-" << "Friend List" << "\n";
        cout << "\n";

        for (int i = 0; FriendList[i] != NULL; i++)
        {
                FriendList[i]->Print();
                cout << "\n";
        }

        cout << "-----------------------------------------------------------------" << "\n";
        cout << "\n";
        cout << "\n";

    }

    void viewlikedpgslist()     //Used to view the list of liked pages
    {
        cout << "Command: ";
        cout << setw(10) << "View Liked Pages List" << "\n";
        cout << "-----------------------------------------------------------------" << "\n";

        cout << this->FirstName << " " << this->LastName << "-" << "Liked Pages" << "\n";
        cout << "\n";


        for (int i = 0; LikedPages[i] != NULL; i++)
        {
            LikedPages[i]->Print();
            cout << "\n";
        }

        cout << "-----------------------------------------------------------------" << "\n";
        cout << "\n";
    }

    void viewpost() //To view post
    {

        int i = 0;
        while (Timeline[i] != NULL)
        {
            cout << this->getfname() << " " << this->getlname();
            
            if (Timeline[i]->get_act() != NULL)
            {
                cout << " is ";
                Timeline[i]->get_act()->get_type();
                cout << " " << Timeline[i]->get_act()->get_v();
                cout << "\n";
            }
            cout << " shared ";
            if (Timeline[i]->get_addtxtformrm() != NULL)
            {
                cout << "~~~" << Timeline[i]->get_sharedBy()->getfname() << " " << Timeline[i]->get_sharedBy()->getlname() << "shared a memory~~~...";                cout << setw(10);
                cout << setw(10);
                Date::get_todaydate();
                cout << "\"" << Timeline[i]->get_addtxtformrm() << "\"" << "\n";

            }

            cout << "\"" << Timeline[i]->get_txt() << "\"" << "............";
            Timeline[i]->get_date()->GetDate();
            viewcomments(Timeline[i]);
            cout << "\n" << "\n";
            i++;

        }

        cout << "-----------------------------------------------------------------" << "\n";
        cout << "\n";
    }

    void viewcomments(Post ptr[])    //View post
    {
        int i = 0;
        while (ptr->get_comm(i) != NULL)
        {
            cout << "\n";
            Base* n = ptr->get_comm(i)->get_person();

            n->Get_info();
            cout << " wrote: ";

            cout << ptr->get_comm(i)->get_txt();

            i++;
        }
    }

   

    void viewTimeline()      //To view timeline
    {
        cout << "Command: ";
        cout << setw(10) << " View Timeline" << "\n";


        cout << "-----------------------------------------------------------------" << "\n";

        cout << this->FirstName << " " << this->LastName << "-" << "Timeline" << "\n";

        cout << "\n";
       // this->viewpost();

        for (int i = 0; Timeline[i] != NULL; i++)
        {
            Timeline[i]->Print();
        }

    }

   

    //void viewpostbytime()      //View post with respect to today's date
    //{
    //    int i = 0;
    //    while (Timeline[i] != NULL)
    //    {
    //        if (Timeline[i]->get_date()->chkda(Date::get_curr_date()) == 1)

    //        {
    //            cout << this->getfname() << " " << this->getlname();
    //            cout << " is ";
    //            if (Timeline[i]->get_act() != NULL)
    //            {

    //                Timeline[i]->get_act()->get_type();
    //                cout << " " << Timeline[i]->get_act()->get_v();
    //                cout << "\n";
    //            }

    //            cout << "\"" << Timeline[i]->get_txt() << "\"" << "............";
    //            Timeline[i]->get_date()->GetDate();
    //            viewcomments(Timeline[i]);
    //            cout << "\n" << "\n";

    //        }
    //        i++;
    //    }
    //}

    void viewhomepage()     //view homepage
    {
        cout << "Command: ";
        cout << setw(10) << "Home Page" << "\n";

        cout << "-----------------------------------------------------------------" << "\n";
        cout << this->FirstName << " " << this->LastName << "-" << "Home Page" << "\n";

        cout << "\n";

        for (int i = 0; FriendList[i] != NULL; i++)
        {
           
            FriendList[i]->Showrecebpostbyobj();
        }

        for (int i = 0; LikedPages[i] != NULL; i++)
        {
            LikedPages[i]->Showrecebpostbyobj();
        }
        cout << "\n";
        cout << "-----------------------------------------------------------------" << "\n";
    }


    void commd()        //Command
    {
        cout << "Command: ";
        cout << setw(10) << "Set current user " << Base::get_ID() << "\n";

        cout << this->FirstName << " " << this->LastName << " " << "successfully set as Current User" << "\n";
        cout << "\n";
    }

    void viewmemory()
    {
       // memor.Allocatememoryfornewpostarray();

        /*for (int i = 0; Timeline[i] != NULL; i++)
        {
            memor.chkmemory(Timeline[i]);
        }*/

        for (int i = 0; Timeline[i] != NULL; i++)
        {
            if (Timeline[i]->cheackformemory() == 1)
            {
                cout << "Command: " << setw(10) << "ViewMemory" << "\n";

                cout << "We hope you enjoy looking back and sharing your memories on Facebook, from the most recent to those long ago." << "\n";
                cout << "On this Day" << "\n";

                Timeline[i]->calculatetime();
                cout << " years ago" << "\n";
                Timeline[i]->viewpost();
            }
        }
    }


    void sharememory(const char postid[], const char txt[])
    {
        
        int i = 0;


            if (Helper::strgcmp(memor.Get_memory(i)->get_ID(), postid) == 1)
            {
                cout << "Command: " << setw(10) << "ShareMemory(" << memor.Get_memory(i)->get_ID() << "," << txt << ")" << "\n";

                AddposttoTimelinei(memor.Get_memory(i));
                memor.Get_memory(i)->viewpost();
                memor.Get_memory(i)->storeextratxtformemory(txt);

                cout << "\n";

            }
            i++;
        
    }

    //Destructor
    ~User()
   {
        if(FirstName)
            delete[] FirstName;
        FirstName = nullptr;
        if(LastName)
            delete[] LastName;
        LastName = nullptr;
        if (FriendList)
            delete[] FriendList;
        FriendList = nullptr;
        if (LikedPages)
            delete[] LikedPages;
        LikedPages = nullptr;


        //int i = 0;
        //for (; FriendList[i] != NULL; i++)
        //{
        //    if(FriendList[i])
        //    delete[] FriendList[i];
        //}
        //delete[] FriendList;
        //i = 0;
        //for (; LikedPages[i] != NULL; i++)
        //{
        //    if(LikedPages[i])
        //    delete[] LikedPages[i];
        //}
        //delete[] LikedPages;

        if (Timeline) 
        {
            for (int i=0; Timeline[i] != NULL; i++)
            {
                if (Timeline[i])
                    delete Timeline[i];
                Timeline[i] = nullptr;
            }
            delete[] Timeline;
            Timeline = nullptr;
        }
        /*FriendList = NULL;
        LikedPages = NULL;
        Timeline = NULL;*/
   }
};

class Facebook
{
private:
    User** UsersList;
    Page** PageList;
    Post** Postlist;
    Comment** CommentList;
    int totalusers;
    int totalpages;
    int totalposts;
    int totalcomments;

public:

    //Associating the Friends in Users class
    void AsssociateFriendList(char*** tempfrnlist)
    {
        //pointer to hold null
        char* temp = nullptr;

        //pointer to be sent for Association
        User* holdptr = nullptr;

        int index = 0;

        for (int i = 0; i < totalusers; i++)
        {
            UsersList[i]->Allocate_memoryfrn();
            index = 0;
            int j = 0;

            while (tempfrnlist[i][j] != temp)
            {
                //Placing the pointer of friend in "holptr"
                holdptr = SearchUserByID(tempfrnlist[i][j]);

                //Sending it to store it in 2-D FriendList
                UsersList[i]->set_frndlist(holdptr, index);
                index++;
                j++;
            }

            //Placing null at the end of the array
            User* ptr = NULL;
            UsersList[i]->set_frndlist(ptr, index);

        }
    }

    //Searching the page by id in the PageList
    Page* SearchPageByID(const char strg[])
    {
        for (int i = 0; i < totalpages; i++)
        {
            if (Helper::strgcmp(strg, PageList[i]->get_id()) == 1)
            {
                return PageList[i];
            }
        }
        Page* ptr = NULL;
        return ptr;
    }

    //Searching the User by id from UserList
    User* SearchUserByID(const char strg[])
    {
        for (int i = 0; i < totalusers; i++)
        {
            if (Helper::strgcmp(strg, UsersList[i]->get_id()) == 1)
            {
                return UsersList[i];
            }
        }
        User* ptr = NULL;
        return ptr;
    }

    void ShareMemory(Base* obj, const char str[], const char txt[])
    {
        Post* post = SearchpostbyID(str);

       
    }

    //Search the id of the obj
    Base* SearchobjByID(const char str[])
    {

        if (str[0] == 'u')
        {
            for (int i = 0; i < totalusers; i++)
            {
                if (Helper::strgcmp(str, UsersList[i]->get_id()) == 1)
                {
                    return UsersList[i];
                }
            }
        }
        if (str[0] == 'p')
        {
            for (int i = 0; i < totalpages; i++)
            {
                if (Helper::strgcmp(str, PageList[i]->get_id()) == 1)
                {
                    return PageList[i];
                }
            }
        }

        return NULL;
    }

    //Search post by ID
    Post* SearchpostbyID(const char str[])
    {
        if (str[0] == 'p')
        {
            for (int i = 0; i < totalposts; i++)
            {
                if (Helper::strgcmp(str, Postlist[i]->get_ID()) == 1)
                {
                    return Postlist[i];
                }
            }
        }
        return NULL;
    }

    //get totalpages
    int get_pgs()
    {
        return totalpages;
    }

    //get totalusers
    int get_users()
    {
        return totalusers;
    }

    Facebook()
    {
        UsersList = NULL;
        PageList = NULL;
        Postlist = NULL;
        CommentList = NULL;
        totalusers = 0;
        totalpages = 0;
        totalposts = 0;
        totalcomments = 0;

    }

    //Load the data of user from the file
    void loadUSerdata(ifstream& in)
    {
        in >> totalusers;

        //creating a trpple pointer to hold the pointers of usres and friends, temporarily
        char*** tempfrnlist = new char** [totalusers];

        //Allocating the temp array to the total number of users
        UsersList = new User * [totalusers];



        for (int i = 0; i < totalusers; i++)
        {
            //creating memory for user i
            UsersList[i] = new User;

            //Reading the id, firstname and lastname of user
            UsersList[i]->ReadfromUser(in);

            int j = 0;

            //creating buffer to store the char e.g "u1" for further functions
            char buffer[10];
            in >> buffer;

            //allocating space for max of 10 friends
            tempfrnlist[i] = new char* [10];

            //cheack for delimiter (-1)
            while (buffer[0] != '-')
            {
                tempfrnlist[i][j] = Helper::GetStringFromBuffer(buffer);
                j++;
                in >> buffer;
            }

            //placing a delimiter NULL at the end of the array of friends by first storring it in a buffer
            buffer[0] = '\0';
            tempfrnlist[i][j] = Helper::GetStringFromBuffer(buffer);

            //Buffer for liked page reading e.g "p1"
            char temppg[10];
            in >> temppg;

            int k = 0;

            //Allocate memory for pointers of liked pages
            UsersList[i]->Allocate_memeorypgs();

            //chaeck for delimiter (-1)
            while (temppg[0] != '-')
            {
                Page* temppointer;

                //Placing the pointer of the page by searching it in the PageList
                temppointer = SearchPageByID(temppg);


                //Placing the pointer in the 2-D Array of LikedPages
                UsersList[i]->set_likedpages(temppointer, k);

                k++;
                in >> temppg;
            }
            //Placing null at the end of the array
            Page* ptr = NULL;
            UsersList[i]->set_likedpages(ptr, k);


        }

        //Function to Associate the firendsin the Users class
        AsssociateFriendList(tempfrnlist);


    }

    //Reading data of the Pages
    void loadPagesdata(ifstream& in)
    {
        in >> totalpages;

        PageList = new Page * [totalpages];

        for (int i = 0; i < totalpages; i++)
        {
            PageList[i] = new Page;
            PageList[i]->ReadFromPage(in);
        }

    }

    //chk whetaher the obj is already in the array
    bool chkobj(Base** ptr, Base* obj)
    {
        for (int i = 0; i < 40; i++)
        {
            if (ptr[i] == obj)
            {
                return 1;
            }
        }
        return 0;
    }


    void LoadPostData(ifstream& in)
    {
        Base* sharedby;
        Base* objthatliked;
        in >> totalposts;
        Postlist = new Post * [50];

        for (int i = 0; i < totalposts; i++)
        {
            Postlist[i] = new Post;

            char buffer[100];
            char likedby[100];
            Postlist[i]->LoadFromFile(in);

            in >> buffer;
            sharedby = SearchobjByID(buffer);
            Postlist[i]->Set_sharedby(sharedby);

            sharedby->AddposttoTimelinei(Postlist[i]);

            in >> likedby;
            int inedexoflikedby = 0;

            while (likedby[0] != '-')
            {
                objthatliked = SearchobjByID(likedby);

                            //storing the obj that liked the posts
                Postlist[i]->Set_LikedBy(objthatliked, inedexoflikedby);

                in >> likedby;
                inedexoflikedby++;
            }        


        }
    }

    //chk if post is already present in th array
    bool chkpost(Post** ptr, Post* obj)
    {
        for (int i = 0; i < 40; i++)
        {
            if (ptr[i] == obj)
            {
                return 1;
            }
        }
        return 0;
    }

  

    void LoadComments(ifstream& in)
    {
        in >> totalcomments;
        CommentList = new Comment * [20];

        Post* postid = NULL;
        Base* commentedby = NULL;

        for (int i = 0; i < totalcomments; i++)
        {
            CommentList[i] = new Comment;

            CommentList[i]->LoadIDFromFile(in);

            char temp[30];
            in >> temp;

            postid = SearchpostbyID(temp);

            in >> temp;
            commentedby = SearchobjByID(temp);
            
            CommentList[i]->Add_obj_that_commented(commentedby);

            CommentList[i]->Loadtxt(in);

            postid->Addcomment(CommentList[i]);
        }
    }
    void LoadData()
    {
        ifstream uin;
        ifstream pin;
        ifstream postin;
        ifstream comin;


        //opeening the fiels to read
        pin.open("Pages.txt");
        uin.open("Users.txt");
        postin.open("Post.txt");
        comin.open("Comments.txt");

        //loading the data
        loadPagesdata(pin);

        //Load user
        loadUSerdata(uin);

        //loading post data
        LoadPostData(postin);

        //load comments
        LoadComments(comin);

    }

    //Destructor
    ~Facebook()
    {
        for (int i = 0; i < totalusers; i++)
        {
            if (UsersList[i])
                delete UsersList[i];
        }
        delete[] UsersList;

        for (int i = 0; i < totalpages; i++)
        {
            if (PageList[i])
                delete PageList[i];
        }
        delete[] PageList;

    }
};

//Driver Function
void RunFacebook()
{
    Facebook fb;
    fb.LoadData();

    cout << "System date set to: " << setw(10);

    Date::Set_currdate(15, 11, 2017);

    User* currUser = fb.SearchUserByID("u7");

    Page* currpage = fb.SearchPageByID("p1");

    if (currUser != NULL)
    {
        currUser->commd();

        currUser->viewfriendlist();
        currUser->viewlikedpgslist();
        currUser->viewTimeline();
    }
    else
    {
        cout << "User not found!" << "\n";
    }
    if (currpage != NULL)
    {
        currpage->viewpage();
    }
    else
    {
        cout << "Page not found!" << "\n";
    }

    currUser->viewhomepage();

    Post* currpost = fb.SearchpostbyID("post4");
    if (currpost != NULL)
    {
        currpost->viewlikedby();

        Base* currobj = fb.SearchobjByID("u7");
        currpost->Likepost(currobj);
        currpost->viewlikedby();

        currpost->viewpost();

        currpost->addcomment(currobj, "Good Luck for your result");

        currpost->viewpost();

    }
    else
    {
        cout << "Post not found!" << "\n";
        cout << "\n";
    }

    currUser->viewmemory();
   // currUser->sharememory("post10", "Never thought I will be specialist in this field....");
    currUser->viewTimeline();
}

int main()
{
    RunFacebook();

    system("pause");
    return 0;
}