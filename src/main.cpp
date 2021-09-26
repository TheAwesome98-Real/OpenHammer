#ifndef OPENHAMMER_VERSION
  #error "Please run 'make clean' then 'make build'."
#endif

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/wfstream.h>

class OpenHammerApp : public wxApp
{
public:
    virtual bool OnInit();
};
class OpenHammerFrame : public wxFrame
{
public:
    OpenHammerFrame();
private:
    void OnOpen(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnSaveAs(wxCommandEvent& event);
};
enum
{
    ID_Open = 1,
    ID_Save = 2,
    ID_SaveAs = 3
};
wxIMPLEMENT_APP(OpenHammerApp);
bool OpenHammerApp::OnInit()
{
    OpenHammerFrame *frame = new OpenHammerFrame();
    frame->Show(true);
    return true;
}
OpenHammerFrame::OpenHammerFrame()
    : wxFrame(NULL, wxID_ANY, "OpenHammer " + OPENHAMMER_VERSION + " - No File")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Open, "&Open...\tCtrl-O", "Open a *.vmf or *.bsp file");
    menuFile->Append(ID_Save, "&Save\tCtrl-S", "Save the content of the map");
    menuFile->Append(ID_SaveAs, "Save &As...\tShift-Ctrl-S", "Save the content of the map in another file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "&Quit\tCtrl-Q", "Quit OpenHammer");
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar( menuBar );
    CreateStatusBar(3, wxSTB_DEFAULT_STYLE | wxSB_SUNKEN);
    SetStatusText("For help, press F1", 0);
    SetStatusText("No selection", 1);
    SetStatusText("Snap: On Grid: 64", 2);
    Bind(wxEVT_MENU, &OpenHammerFrame::OnOpen, this, ID_Open);
    Bind(wxEVT_MENU, &OpenHammerFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &OpenHammerFrame::OnExit, this, wxID_EXIT);
}
void OpenHammerFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
void OpenHammerFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("OpenHammer is a map editor", "About OpenHammer " + OPENHAMMER_VERSION, wxOK | wxICON_INFORMATION);
}
void OpenHammerFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Open map file"), "", "", "Valve Map Format Files and Compiled Map Files (*.vmf;*.bsp)|*.vmf;*.bsp|Valve Map Format Files (*.vmf)|*.vmf|Compiled Map Files (*.bsp)|*.bsp|Any file (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL) return;     // cancel, the user doesn't want to anymore
    
    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
    wxFileInputStream input_stream(openFileDialog.GetPath());
    if (!input_stream.IsOk())
    {
        wxMessageBox("An error ocurred while opening the file '" + openFileDialog.GetPath() + "'.", "Failed", wxOK | wxICON_ERROR);
        return;
    } else {
        wxMessageBox("Successfully opened file '" + openFileDialog.GetPath() + "'.", "Success", wxOK | wxICON_INFORMATION);
        OpenHammerFrame::SetTitle("OpenHammer " + OPENHAMMER_VERSION + " - " + openFileDialog.GetFilename());
    }
}

