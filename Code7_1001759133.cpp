#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<gtkmm.h>

using namespace std;

class MyWindow: public Gtk::Window
{
    public:
        MyWindow()
        {
            set_default_size(400,200);
            set_title("Welcome to My Guessing Game");
            set_position(Gtk::WIN_POS_CENTER);

            Gtk::Box *MainVBox =Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
            add(*MainVBox);

            Gtk::MenuBar *MyMenuBar = Gtk::manage(new Gtk::MenuBar());
            MainVBox->pack_start(*MyMenuBar, Gtk::PACK_SHRINK, 0);
            
            Gtk::MenuItem *MyEnemyHints = Gtk::manage(new Gtk::MenuItem("_Enemy Hints", true));
            MyMenuBar->append(*MyEnemyHints);
            Gtk::Menu *MyEnemyHintsSubMenu = Gtk::manage(new Gtk::Menu());
            MyEnemyHints->set_submenu(*MyEnemyHintsSubMenu);
            Gtk::MenuItem *SubMenuItem_Anita =Gtk::manage(new Gtk::MenuItem("_Anita", true));
            MyEnemyHintsSubMenu->append(*SubMenuItem_Anita);
            Gtk::MenuItem *SubMenuItem_Roger =Gtk::manage(new Gtk::MenuItem("_Roger", true));
            MyEnemyHintsSubMenu->append(*SubMenuItem_Roger);
            
            Gtk::MenuItem *MyAlliesHints  = Gtk::manage(new Gtk::MenuItem("_Allies Hints", true));
            MyMenuBar->append(*MyAlliesHints );
            Gtk::Menu *MyAlliesHintsSubMenu = Gtk::manage(new Gtk::Menu());
            MyAlliesHints ->set_submenu(*MyAlliesHintsSubMenu);
            Gtk::MenuItem *SubMenuItem_Jasper =Gtk::manage(new Gtk::MenuItem("_Jasper", true));
            MyAlliesHintsSubMenu->append(*SubMenuItem_Jasper);
            Gtk::MenuItem *SubMenuItem_Horace =Gtk::manage(new Gtk::MenuItem("_Horace", true));
            MyAlliesHintsSubMenu->append(*SubMenuItem_Horace);

            Gtk::MenuItem *MyPetHints  = Gtk::manage(new Gtk::MenuItem("_Pet Hints", true));
            MyMenuBar->append(*MyPetHints );
            Gtk::Menu *MyPetHintsSubMenu = Gtk::manage(new Gtk::Menu());
            MyPetHints ->set_submenu(*MyPetHintsSubMenu);
            Gtk::MenuItem *SubMenuItem_Pongo =Gtk::manage(new Gtk::MenuItem("_Pongo", true));
            MyPetHintsSubMenu->append(*SubMenuItem_Pongo);
            Gtk::MenuItem *SubMenuItem_Perdita =Gtk::manage(new Gtk::MenuItem("_Perdita", true));
            MyPetHintsSubMenu->append(*SubMenuItem_Perdita);

            Gtk::Label *YourLabel  = Gtk::manage (new Gtk::Label("\n\nWhat is this cartoon character's name?\n\n"));
            MainVBox->pack_start(*YourLabel, Gtk::PACK_SHRINK, 0);
            
            Gtk::Image *MyImage = Gtk::manage (new Gtk::Image("CruellaDeVil.png"));
            MainVBox->pack_start(*MyImage,Gtk::PACK_SHRINK, 0);

            Gtk::Box *hBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
            MainVBox->add(*hBox); 
            
            Gtk::Box *vBox1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
            hBox->pack_end(*vBox1, Gtk::PACK_SHRINK, 0);

            Gtk::Box *vBox2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
            hBox->pack_end(*vBox2, Gtk::PACK_SHRINK, 0);
            
            Gtk::Entry *entrybox = Gtk::manage(new Gtk::Entry());
            entrybox->set_text("Enter your guess here ");
            vBox1->add(*entrybox);

            Gtk::Button* buttonC = Gtk::manage(new Gtk::Button("Cancel"));
            buttonC->set_border_width(10);
            buttonC->signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::on_Button_click));

            Gtk::Button* buttonO = Gtk::manage(new Gtk::Button("Ok"));
            buttonO->set_border_width(10);
            buttonO->signal_clicked().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this,&MyWindow::ok_Button_click),entrybox));
            entrybox->signal_activate().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this,&MyWindow::ok_Button_click),entrybox));

            vBox2->pack_start(*buttonO,Gtk::PACK_SHRINK, 0);
            vBox2->pack_start(*buttonC,Gtk::PACK_SHRINK, 0);

            MainVBox->show_all();
        }
        void on_Button_click();
        void ok_Button_click(Gtk::Entry* entrybox);
};

void MyWindow::on_Button_click()
{
    hide();
}

void MyWindow::ok_Button_click(Gtk::Entry *entrybox)
{
    if(entrybox->get_text().compare("Cruella") ==0)
    {
        Gtk::MessageDialog dlg("You guessed correctly!!", false, Gtk::MESSAGE_WARNING, Gtk::BUTTONS_OK, true);
        dlg.set_secondary_text("<span fgcolor='#0000ff'>correctly</span>", true);
        dlg.run();
        hide();
    }
    else
    {
        Gtk::MessageDialog dlg("Your answer is not correct.\nPlease try again", false,Gtk::MESSAGE_ERROR, Gtk::BUTTONS_OK, true);
        dlg.set_secondary_text("<span fgcolor='#ff0000'>correct</span>", true);
        dlg.run();
    }
}

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "");
    MyWindow object;
    app->run(object);
    return 0;
}