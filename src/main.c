#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "../includes/functions.h"

//declaration des fenetres:


GtkBuilder *builder;
GtkWidget *mainWindow;
GtkWidget *mainGrid;
GtkWidget *header;
GtkWidget *panel;
GtkWidget *addA;
GtkWidget *addL;
GtkWidget *sideNav;
GtkWidget *listPort;
GtkWidget *typeL;
GtkWidget *radPort;
GtkWidget *catL;
GtkWidget *catPort;
GtkWidget *radGrid;
GtkWidget *ra;
GtkWidget *rl;
GtkWidget *all;
GtkWidget *spec;
GtkWidget *cats;
GtkWidget *catGrid;
GtkWidget *list;
GtkWidget *listGrid;
GtkWidget *sgrid;
GtkWidget *adhs;
GtkWidget *searchB;
GtkWidget *searchEnt;
GtkWidget *ajout_l;
GtkWidget *modif_l;
GtkWidget *supp_l;
GtkWidget *cherche_l;
GtkWidget *ajout_a;
GtkWidget *modif_a;
GtkWidget *supp_a;
GtkWidget *cherche_a;
GtkWidget *emprunt;
GtkWidget *rendre;
GtkWidget *aj_l;
GtkWidget *mo_l;
GtkWidget *sup_l;
GtkWidget *ch_l;
GtkWidget *aj_a;
GtkWidget *mo_a;
GtkWidget *sup_a;
GtkWidget *ch_a;
GtkWidget *empr;
GtkWidget *rendre;
GtkBuilder *builder2;
GtkWidget *sau1;
GtkWidget *na3;
GtkWidget *noa3;
GtkWidget *pa3;
GtkWidget *ea3;
GtkWidget *aa3;
GtkWidget *sau;
GtkWidget *nl3;
GtkWidget *tl3;
GtkWidget *cl3;
GtkWidget *al3;
GtkWidget *sup1;
GtkWidget *nas1;
GtkWidget *sup;
GtkWidget *nls1;
GtkWidget *nae1;
GtkWidget *nle1;
GtkWidget *emp;


// variables et tables utilisés.

GtkWidget *lables[1000];
int numAdh = 1;
int numLiv = 1;
int adhOuLiv = 0; // 1 si on veut afficher les adherents et 0 sinon.
list_adherent ladh;
list_livre lliv;

//declaration des signaux :
void destr();
void on_adh_taggeled(GtkRadioButton *);
void on_liv_taggeled(GtkRadioButton *);
void afficher_liv(int,list_livre,GtkWidget *lables[1000]);
void afficher_adh(int,list_adherent,GtkWidget *lables[1000]);
void al(GtkWidget *widget,gpointer data);
void aa(GtkWidget *widget,gpointer data);
void sup_ll(GtkWidget *widget,gpointer data);
void sup_aa(GtkWidget *widget,gpointer data);
void mol(GtkWidget *widget,gpointer data);
void moa(GtkWidget *widget,gpointer data);
void ch_aa(GtkWidget *widget,gpointer data);
void ch_ll(GtkWidget *widget,gpointer data);
void emp_l(GtkWidget *widget,gpointer data);
void rend(GtkWidget *widget,gpointer data);
int powInt(int x, int y);
int parseInt(char* chars);
int sauva(GtkWidget *widget,gpointer data);
int sauv(GtkWidget *widget,gpointer data);
void supa(GtkWidget *widget,gpointer data);
void supl(GtkWidget *widget,gpointer data);
void empl(GtkWidget *widget,gpointer data);



int main(int argc,char **argv){
    //charger(&numAdh,&ladh,&numLiv,&lliv);
    lliv = Malloc(livre);
    lliv->info_liv = Malloc(liv_info);
    sprintf(lliv->info_liv->titre_livre,"jkbkjbkjbkjb");
    lliv->info_liv->num_liv = 5;
    gtk_init(&argc,&argv);
    ladh = Malloc(adherent);
    ladh->info_adh = Malloc(adh_info);
    sprintf(ladh->info_adh->email_adh,"farfora@haha.com");
    sprintf(ladh->info_adh->nom_adh,"hammmiiid");
    sprintf(ladh->info_adh->prenom_adh,"dhdhdh");
    ladh->info_adh->nbre_emprunts_adh = 5;



    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    builder = gtk_builder_new_from_file ("./glade/GUIMain.glade");
    mainWindow = GTK_WIDGET(gtk_builder_get_object(builder,"mainWindow"));
    mainGrid = GTK_WIDGET(gtk_builder_get_object(builder,"mainGrid"));
    header = GTK_WIDGET(gtk_builder_get_object(builder,"header"));
    panel = GTK_WIDGET(gtk_builder_get_object(builder,"panel"));
    all = GTK_WIDGET(gtk_builder_get_object(builder,"all"));
    spec = GTK_WIDGET(gtk_builder_get_object(builder,"spec"));
    addA = GTK_WIDGET(gtk_builder_get_object(builder,"addA"));
    addL = GTK_WIDGET(gtk_builder_get_object(builder,"addL"));
    sideNav = GTK_WIDGET(gtk_builder_get_object(builder,"sideNav"));
    listPort = GTK_WIDGET(gtk_builder_get_object(builder,"listPort"));
    listGrid = GTK_WIDGET(gtk_builder_get_object(builder,"listGrid"));
    sgrid = GTK_WIDGET(gtk_builder_get_object(builder,"sgrid"));
    adhs = GTK_WIDGET(gtk_builder_get_object(builder,"adhs"));
    radPort = GTK_WIDGET(gtk_builder_get_object(builder,"radPort"));
    searchB = GTK_WIDGET(gtk_builder_get_object(builder,"searchB"));
    catL = GTK_WIDGET(gtk_builder_get_object(builder,"catL"));
    catPort = GTK_WIDGET(gtk_builder_get_object(builder,"catPort"));
    radGrid = GTK_WIDGET(gtk_builder_get_object(builder,"radGrid"));
    list = GTK_WIDGET(gtk_builder_get_object(builder,"list"));
    typeL = GTK_WIDGET(gtk_builder_get_object(builder,"typeL"));
    searchEnt = GTK_WIDGET(gtk_builder_get_object(builder,"searchEnt"));
    ra = GTK_WIDGET(gtk_builder_get_object(builder,"ra"));
    rl = GTK_WIDGET(gtk_builder_get_object(builder,"rl"));
    ajout_l = GTK_WIDGET(gtk_builder_get_object(builder,"ajout_l"));
    modif_l = GTK_WIDGET(gtk_builder_get_object(builder,"modif_l"));
    supp_l = GTK_WIDGET(gtk_builder_get_object(builder,"supp_l"));
    cherche_l = GTK_WIDGET(gtk_builder_get_object(builder,"cherche_l"));
    ajout_a = GTK_WIDGET(gtk_builder_get_object(builder,"ajout_a"));
    modif_a = GTK_WIDGET(gtk_builder_get_object(builder,"modif_a"));
    supp_a = GTK_WIDGET(gtk_builder_get_object(builder,"supp_a"));
    cherche_a = GTK_WIDGET(gtk_builder_get_object(builder,"cherche_a"));
    emprunt = GTK_WIDGET(gtk_builder_get_object(builder,"emprunter_l"));
    rendre = GTK_WIDGET(gtk_builder_get_object(builder,"rendre"));
    sau1=GTK_WIDGET(gtk_builder_get_object(builder2,"sau1"));
    sau=GTK_WIDGET(gtk_builder_get_object(builder2,"sau"));
    sup1=GTK_WIDGET(gtk_builder_get_object(builder2,"sup1"));
    sup=GTK_WIDGET(gtk_builder_get_object(builder2,"sup"));
    emp=GTK_WIDGET(gtk_builder_get_object(builder2,"emp"));

    //affichage :
    int i;
    for(i=0;i<1000;i++){
        lables[i] = gtk_label_new("");
        gtk_grid_attach(GTK_GRID(adhs),lables[i],1,i,1,1);
    }
    if(adhOuLiv==0){
        afficher_liv(numLiv,lliv,lables);
    }
    else{
        afficher_adh(numAdh,ladh,lables);
    }
    
    

    // signals :
    //g_signal_connect(searchB,"clicked",G_CALLBACK(ll),NULL);
    g_signal_connect(mainWindow,"destroy",G_CALLBACK(destr),NULL);
    g_signal_connect(rl,"toggled",G_CALLBACK(on_liv_taggeled),NULL);
    g_signal_connect(ra,"toggled",G_CALLBACK(on_adh_taggeled),NULL);
    gtk_builder_connect_signals(builder,NULL);
    g_signal_connect(ajout_l,"activate",G_CALLBACK(al),NULL);
    g_signal_connect(modif_l,"activate",G_CALLBACK(mol),NULL);
    g_signal_connect(supp_l,"avtivate",G_CALLBACK(sup_ll),NULL);
    g_signal_connect(cherche_l,"activate",G_CALLBACK(ch_ll),NULL);
    g_signal_connect(ajout_a,"activate",G_CALLBACK(aa),NULL);
    g_signal_connect(modif_a,"activate",G_CALLBACK(moa),NULL);
    g_signal_connect(supp_a,"activate",G_CALLBACK(sup_aa),NULL);
    g_signal_connect(cherche_a,"activate",G_CALLBACK(ch_aa),NULL);
    g_signal_connect(emprunt,"avtivate",G_CALLBACK(emp_l),NULL);
    g_signal_connect(rendre,"activate",G_CALLBACK(rend),NULL);
    g_signal_connect(sau1,"clicked",G_CALLBACK(sauva),NULL);
    g_signal_connect(sau,"clicked",G_CALLBACK(sauv),NULL);
    g_signal_connect(sup1,"clicked",G_CALLBACK(supa),NULL);
    g_signal_connect(sup,"clicked",G_CALLBACK(supl),NULL);
    g_signal_connect(emp,"clicked",G_CALLBACK(empl),NULL);
      

    gtk_widget_show_all(mainWindow);
    

    gtk_main();
    free(lliv->info_liv);
    free(lliv);
    free(ladh->info_adh);
    free(ladh);
    return 0;
}

// code des signaux:
void destr(){
    exit(0);
}

void on_adh_taggeled(GtkRadioButton *b){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        adhOuLiv = 1;
        afficher_adh(numAdh,ladh,lables);
    }
    return;
}
void on_liv_taggeled(GtkRadioButton *b){
    gboolean t = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if(t){
        adhOuLiv = 0;
        afficher_liv(numLiv,lliv,lables);
        }
    return;
}
void afficher_liv(int numLiv,list_livre head,GtkWidget *lables[1000]){
    int i;
    list_livre p = head;
    char *temp = (char*)malloc(1000*sizeof(char));
    char *temp1 = (char*)malloc(50*sizeof(char));
    for(i=0;i<numLiv;i++){
        sprintf(temp,"titre : %s\n",head->info_liv->titre_livre);
        temp = strcat(temp,"Auteur : ");
        temp = strcat(temp,head->info_liv->auteur_liv.prenom_aut);
        temp = strcat(temp," ");
        temp = strcat(temp,head->info_liv->auteur_liv.nom_aut);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"Catégorie : ");
        temp = strcat(temp,head->info_liv->categ_liv);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"Numéro de livre : ");
        sprintf(temp1,"%d\n",head->info_liv->num_liv);
        temp = strcat(temp,temp1);
        temp = strcat(temp,"Numéro de l'emprunteur : ");
        sprintf(temp1,"%d\n",head->info_liv->emprunteur_liv);
        temp = strcat(temp,temp1);
        temp = strcat(temp,"___________________________________________________________________________________________\n\n");
        gtk_label_set_text(GTK_LABEL(lables[i]),temp);
        p = p->next;
    }
    free(temp);
    free(temp1);
}
void afficher_adh(int numAdh,list_adherent head,GtkWidget *lables[1000]){
    int i;
    list_adherent p = head;
    char *temp = (char*)malloc(1000*sizeof(char));
    char *temp1 = (char*)malloc(50*sizeof(char));;
    for(i=0;i<numAdh;i++){
        sprintf(temp,"Prénom : %s\n",head->info_adh->prenom_adh);
        temp = strcat(temp,"Nom : ");
        temp = strcat(temp,head->info_adh->nom_adh);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"émail : ");
        temp = strcat(temp,head->info_adh->email_adh);
        temp = strcat(temp,"\n");
        temp = strcat(temp,"Address : ");
        temp = strcat(temp,head->info_adh->adress_adh);
        temp = strcat(temp,"\n");
        sprintf(temp1,"nombre d'emprunts : %d\n",head->info_adh->nbre_emprunts_adh);
        temp = strcat(temp,temp1);
        temp = strcat(temp,"___________________________________________________________________________________________\n\n");
        gtk_label_set_text(GTK_LABEL(lables[i]),temp);
        p = p->next;
    }
    free(temp);
    free(temp1);
}
void al(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *aj_l;
    GtkWidget *g1;
    GtkWidget *nl1;
    GtkWidget *tl1;
    GtkWidget *cl1;
    GtkWidget *al1;
    GtkWidget *nl;
    GtkWidget *tl;
    GtkWidget *cl;
    GtkWidget *al;
    GtkWidget *aj;
    aj_l = GTK_WIDGET(gtk_builder_get_object(builder2,"aj_l"));
    g1 = GTK_WIDGET(gtk_builder_get_object(builder2,"g1"));
    nl1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nl1"));
    tl1 = GTK_WIDGET(gtk_builder_get_object(builder2,"tl1"));
    cl1 = GTK_WIDGET(gtk_builder_get_object(builder2,"cl1"));
    al1 = GTK_WIDGET(gtk_builder_get_object(builder2,"al1"));
    nl = GTK_WIDGET(gtk_builder_get_object(builder2,"nl"));
    tl = GTK_WIDGET(gtk_builder_get_object(builder2,"tl"));
    cl = GTK_WIDGET(gtk_builder_get_object(builder2,"cl"));
    al = GTK_WIDGET(gtk_builder_get_object(builder2,"al"));
    aj = GTK_WIDGET(gtk_builder_get_object(builder2,"aj"));
    
    gtk_widget_show_all(aj_l);
}
void aa(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *aj_a;
    GtkWidget *g2;
    GtkWidget *na;
    GtkWidget *noa;
    GtkWidget *pa;
    GtkWidget *ea;
    GtkWidget *aa;
    GtkWidget *na1;
    GtkWidget *noa1;
    GtkWidget *pa1;
    GtkWidget *ea1;
    GtkWidget *aa1;
    GtkWidget *aja;
    aj_a = GTK_WIDGET(gtk_builder_get_object(builder2,"aj_a"));
    g2 = GTK_WIDGET(gtk_builder_get_object(builder2,"g2"));
    na = GTK_WIDGET(gtk_builder_get_object(builder2,"na"));
    noa = GTK_WIDGET(gtk_builder_get_object(builder2,"noa"));
    pa = GTK_WIDGET(gtk_builder_get_object(builder2,"pa"));
    ea = GTK_WIDGET(gtk_builder_get_object(builder2,"ea"));
    aa = GTK_WIDGET(gtk_builder_get_object(builder2,"aa"));
    na1 = GTK_WIDGET(gtk_builder_get_object(builder2,"na1"));
    noa1 = GTK_WIDGET(gtk_builder_get_object(builder2,"noa1"));
    pa1 = GTK_WIDGET(gtk_builder_get_object(builder2,"pa1"));
    ea1 = GTK_WIDGET(gtk_builder_get_object(builder2,"ea1"));
    aa1 = GTK_WIDGET(gtk_builder_get_object(builder2,"aa1"));
    aja = GTK_WIDGET(gtk_builder_get_object(builder2,"aja"));
    
    gtk_widget_show_all(aj_a);
}
void sup_ll(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *sup_l;
    GtkWidget *g3;
    GtkWidget *nls1;
    GtkWidget *nls;
    GtkWidget *sup;

    sup_l = GTK_WIDGET(gtk_builder_get_object(builder2,"sup_l"));
    g3 = GTK_WIDGET(gtk_builder_get_object(builder2,"g3"));
    nls1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nls1"));
    nls = GTK_WIDGET(gtk_builder_get_object(builder2,"nls"));
    sup = GTK_WIDGET(gtk_builder_get_object(builder2,"sup"));
    
    
    gtk_widget_show_all(sup_l);
}
void sup_aa(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *sup_a;
    GtkWidget *g4;
    GtkWidget *nas1;
    GtkWidget *nas;
    GtkWidget *sup1;

    sup_a = GTK_WIDGET(gtk_builder_get_object(builder2,"sup_a"));
    g4 = GTK_WIDGET(gtk_builder_get_object(builder2,"g4"));
    nas1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nas1"));
    nas = GTK_WIDGET(gtk_builder_get_object(builder2,"nas"));
    sup1 = GTK_WIDGET(gtk_builder_get_object(builder2,"sup1"));
    
    
    gtk_widget_show_all(sup_a);
}
void mol(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *mo_l;
    GtkWidget *g5;
    GtkWidget *nl3;
    GtkWidget *tl3;
    GtkWidget *cl3;
    GtkWidget *al3;
    GtkWidget *nl2;
    GtkWidget *tl2;
    GtkWidget *cl2;
    GtkWidget *al2;
    GtkWidget *sau;
    mo_l = GTK_WIDGET(gtk_builder_get_object(builder2,"mo_l"));
    g5 = GTK_WIDGET(gtk_builder_get_object(builder2,"g5"));
    nl3 = GTK_WIDGET(gtk_builder_get_object(builder2,"nl3"));
    tl3 = GTK_WIDGET(gtk_builder_get_object(builder2,"tl3"));
    cl3 = GTK_WIDGET(gtk_builder_get_object(builder2,"cl3"));
    al3 = GTK_WIDGET(gtk_builder_get_object(builder2,"al3"));
    nl2 = GTK_WIDGET(gtk_builder_get_object(builder2,"nl2"));
    tl2 = GTK_WIDGET(gtk_builder_get_object(builder2,"tl2"));
    cl2 = GTK_WIDGET(gtk_builder_get_object(builder2,"cl2"));
    al2 = GTK_WIDGET(gtk_builder_get_object(builder2,"al2"));
    sau = GTK_WIDGET(gtk_builder_get_object(builder2,"sau"));
    
    gtk_widget_show_all(mo_l);
}
void moa(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *mo_a;
    GtkWidget *g6;
    GtkWidget *na2;
    GtkWidget *noa2;
    GtkWidget *pa2;
    GtkWidget *ea2;
    GtkWidget *aa2;
    GtkWidget *na3;
    GtkWidget *noa3;
    GtkWidget *pa3;
    GtkWidget *ea3;
    GtkWidget *aa3;
    GtkWidget *sau1;
    mo_a = GTK_WIDGET(gtk_builder_get_object(builder2,"mo_a"));
    g6 = GTK_WIDGET(gtk_builder_get_object(builder2,"g6"));
    na2 = GTK_WIDGET(gtk_builder_get_object(builder2,"na2"));
    noa2 = GTK_WIDGET(gtk_builder_get_object(builder2,"noa2"));
    pa2 = GTK_WIDGET(gtk_builder_get_object(builder2,"pa2"));
    ea2 = GTK_WIDGET(gtk_builder_get_object(builder2,"ea2"));
    aa2 = GTK_WIDGET(gtk_builder_get_object(builder2,"aa2"));
    na3 = GTK_WIDGET(gtk_builder_get_object(builder2,"na3"));
    noa3 = GTK_WIDGET(gtk_builder_get_object(builder2,"noa3"));
    pa3 = GTK_WIDGET(gtk_builder_get_object(builder2,"pa3"));
    ea3 = GTK_WIDGET(gtk_builder_get_object(builder2,"ea3"));
    aa3 = GTK_WIDGET(gtk_builder_get_object(builder2,"aa3"));
    sau1 = GTK_WIDGET(gtk_builder_get_object(builder2,"sau1"));
    
    gtk_widget_show_all(mo_a);
}
void ch_aa(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *ch_a;
    GtkWidget *g7;
    GtkWidget *nac1;
    GtkWidget *nac;
    GtkWidget *ch1;

    ch_a = GTK_WIDGET(gtk_builder_get_object(builder2,"ch_a"));
    g7 = GTK_WIDGET(gtk_builder_get_object(builder2,"g7"));
    nac1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nac1"));
    nac = GTK_WIDGET(gtk_builder_get_object(builder2,"nac"));
    ch1 = GTK_WIDGET(gtk_builder_get_object(builder2,"ch1"));
    
    
    gtk_widget_show_all(ch_a);
}
void ch_ll(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *ch_l;
    GtkWidget *g8;
    GtkWidget *clc;
    GtkWidget *tlc;
    GtkWidget *clc1;
    GtkWidget *ch1;
    GtkWidget *tlc1;

    ch_l = GTK_WIDGET(gtk_builder_get_object(builder2,"ch_l"));
    g8 = GTK_WIDGET(gtk_builder_get_object(builder2,"g8"));
    clc = GTK_WIDGET(gtk_builder_get_object(builder2,"clc"));
    tlc = GTK_WIDGET(gtk_builder_get_object(builder2,"tlc"));
    clc1 = GTK_WIDGET(gtk_builder_get_object(builder2,"clc1"));
    ch1 = GTK_WIDGET(gtk_builder_get_object(builder2,"ch1"));
    tlc1 = GTK_WIDGET(gtk_builder_get_object(builder2,"tlc1"));
    
    
    gtk_widget_show_all(ch_l);
}
void emp_l(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *empr;
    GtkWidget *g9;
    GtkWidget *nae;
    GtkWidget *nle;
    GtkWidget *nae1;
    GtkWidget *nle1;
    GtkWidget *emp;

    empr = GTK_WIDGET(gtk_builder_get_object(builder2,"empr"));
    g9 = GTK_WIDGET(gtk_builder_get_object(builder2,"g9"));
    nae = GTK_WIDGET(gtk_builder_get_object(builder2,"nae"));
    nle = GTK_WIDGET(gtk_builder_get_object(builder2,"nle"));
    nae1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nae1"));
    nle1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nle1"));
    emp = GTK_WIDGET(gtk_builder_get_object(builder2,"emp"));
    
    
    gtk_widget_show_all(empr);
}
void rend(GtkWidget *widget,gpointer data){
    builder2 = gtk_builder_new_from_file ("./glade/windows.glade");
    GtkWidget *rendre;
    GtkWidget *g10;
    GtkWidget *nlr;
    GtkWidget *nlr1;
    GtkWidget *ren;

    rendre = GTK_WIDGET(gtk_builder_get_object(builder2,"rendre"));
    g10 = GTK_WIDGET(gtk_builder_get_object(builder2,"g10"));
    nlr = GTK_WIDGET(gtk_builder_get_object(builder2,"nlr"));
    nlr1 = GTK_WIDGET(gtk_builder_get_object(builder2,"nlr1"));
    ren = GTK_WIDGET(gtk_builder_get_object(builder2,"ren"));
    
    
    gtk_widget_show_all(rendre);
}
int powInt(int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        x *= 10;
    }
    return x;
}

int parseInt(char* chars)
{
    int sum = 0;
    int len = strlen(chars);
    for (int x = 0; x < len; x++)
    {
        int n = chars[len - (x + 1)] - '0';
        sum = sum + powInt(n, x);
    }
    return sum;
}
int sauva(GtkWidget *widget,gpointer data){
    na3=GTK_WIDGET(gtk_builder_get_object(builder2,"na3"));
    noa3=GTK_WIDGET(gtk_builder_get_object(builder2,"noa3"));
    pa3=GTK_WIDGET(gtk_builder_get_object(builder2,"pa3"));
    ea3=GTK_WIDGET(gtk_builder_get_object(builder2,"ea3"));
    aa3=GTK_WIDGET(gtk_builder_get_object(builder2,"aa3"));
    adh_info a;
    strcpy(a.nom_adh,gtk_entry_get_text ( GTK_ENTRY(noa3)));
    strcpy(a.prenom_adh,gtk_entry_get_text ( GTK_ENTRY(pa3) ));
    strcpy(a.email_adh,gtk_entry_get_text ( GTK_ENTRY(ea3) ));
    strcpy(a.adress_adh,gtk_entry_get_text ( GTK_ENTRY(aa3) ));
    a.num_adh=parseInt(strdup(gtk_entry_get_text ( GTK_ENTRY(na3) )));
    a.nbre_emprunts_adh=0;
    adh_info* b;
    b=&a;
    adherent *p;
    p=ladh;
    while(p->next!=NULL){
         if (p->info_adh->num_adh==a.num_adh){
             ladh=modifier_adherent(ladh,b);
             return 0;
             
         }
    }
    ladh=ajouter_adherent(ladh,b);
    return 0;
}
int sauv(GtkWidget *widget,gpointer data){
    nl3=GTK_WIDGET(gtk_builder_get_object(builder2,"nl3"));
    tl3=GTK_WIDGET(gtk_builder_get_object(builder2,"tl3"));
    cl3=GTK_WIDGET(gtk_builder_get_object(builder2,"cl3"));
    al3=GTK_WIDGET(gtk_builder_get_object(builder2,"al3"));
    liv_info a;
    strcpy(a.titre_livre,gtk_entry_get_text ( GTK_ENTRY(tl3) ));
    strcpy(a.categ_liv,gtk_entry_get_text ( GTK_ENTRY(cl3) ));
    a.num_liv=parseInt(strdup(gtk_entry_get_text ( GTK_ENTRY(nl3) )));
    a.emprunteur_liv=0;
    liv_info* b;
    b=&a;
    livre *p;
    p=lliv;
    while(p->next!=NULL){
         if (p->info_liv->num_liv==a.num_liv){
             lliv=modifier_livre(lliv,b);
             return 0;
         }
    }
    lliv=ajouter_livre(lliv,b);
    return 0;
}
void supa(GtkWidget *widget,gpointer data){
    nas1=GTK_WIDGET(gtk_builder_get_object(builder2,"nas1"));
    int code;
    code=parseInt(strdup(gtk_entry_get_text ( GTK_ENTRY(nas1) )));
     supprimes_adherent(ladh, code);
}
void supl(GtkWidget *widget,gpointer data){
    nls1=GTK_WIDGET(gtk_builder_get_object(builder2,"nls1"));
    int code;
    code=parseInt(strdup(gtk_entry_get_text ( GTK_ENTRY(nls1) )));
     supprimes_livre(lliv, code);
}
void empl(GtkWidget *widget,gpointer data){
    nae1=GTK_WIDGET(gtk_builder_get_object(builder2,"nae1"));
    nle1=GTK_WIDGET(gtk_builder_get_object(builder2,"nle1"));
    int code1,code2;
    code1=parseInt(strdup(gtk_entry_get_text ( GTK_ENTRY(nae1)) ));
    code2=parseInt(strdup(gtk_entry_get_text ( GTK_ENTRY(nle1) )));
    
    enprunter_livre(ladh,lliv,code1,code2);
}

