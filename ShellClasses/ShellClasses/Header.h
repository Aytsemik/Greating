#include <string>
#include <list>
class User
{ private:
	int m_user_ID;
    std::string m_fullName;
    std::string m_e_mail;
    std::string m_username;
    std::string m_password;
    std::string m_picture;
public:
    User(std::string fullName, std::string e_mail, std::string username, std::string password, std::string picture); //SignUp
    User(int user_ID, std::string fullName, std::string e_mail,std:: string picture) ;                                //SignIn 
    void  Add();

public: 
	std::list<Document> documentsOfCurrentUser;
    std::list<Workspace> workspacesOfCurrentUser;
    std::list<Comment> commentsOfCurrentUser;

};
class Document
{ private:
	int m_document_ID;
    std::string m_path;
    std::string m_title;
    std::string m_extension;
    size_t m_size;
    int m_owner_ID;
    int m_version;
    int m_workspace_ID;
    std::string m_visibility_status;
public:
     Document(std::string path,int workspace_ID, std::string visibility_status, std::list<int> user_IDs) ;//get from db
     Document(int document_ID, std::string title, std::string extension, size_t size, int owner_ID, std::list<int> user_IDs, int version, int workspace_ID, string visibility_status); //creates
     void Upload();
     void Delete();
     void Rename(std::string new_name);
     void Move(int new_workspace_ID);
     void Edit();
     Document Search(std::string doc_name, int workspace_id=0);
     void Share(std::list<int> user_IDs );
     void Show();
     void Archive();
public:
     std::list<Comment> commentsOfThisDocument;
     std::list<int> IDsOfThoseUsersWhoCanSeeThisDocument;

};

class Workspace
{ private:
	int m_workspace_ID;
    std::string m_title;
public:
    Workspace(std::string title);
    Workspace(int wsID, std::string title);
    void Create();
    void Delete();
    void Rename(std::string newName);
    void Show();
public:
   std:: list<Document> docsInCurrentWorkspace;

};
class Comment
{ private:
	int m_comment_ID;
    std::string m_text;
    int m_user_ID;
    int m_document_ID;
public:
   Comment(std::string text, int docID);
   Comment(int commentID,std:: string text, int docID, std::string OwnerID);
   void comment_todoc();
   void Delete();
   void Show();



};
class Notification
{ private:
	int m_notification_ID;
    int m_owner_ID;
    bool m_type ; // commented,shared
    int m_doc_ID;
    int m_user_ID;
public:
    Notification(int ownerID, int docID);
    Notification(int ownerID, int docID,  std::list<int> usersNotificationIsAbout);
    Notification(int notID, bool type, int ownerID, int docID,  std::list<int> usersNotificationIsAbout );
   void Create();
   void Show(bool type);
   void Delete() ;
public:
   std::list<int> usersNotificationIsAbout  ; 

};