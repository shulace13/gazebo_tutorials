#include <functional>
#include <gazebo/gui/GuiIface.hh>
#include <gazebo/rendering/rendering.hh>
#include "gazebo/gazebo.hh"

namespace gazebo{
    class SystemGUI : public SystemPlugin{
        //---------------------------------//
        // Destructor
        public: virtual ~SystemGUI(){
            this->connections.clear();
            if (this->userCam)
                this->userCam->EnableSaveFrame(false);
            this->userCam.reset();
        }
        
        //---------------------------------//
        // Called after the plugin has been constructed.
        public: void Load(int /*_argc*/, char ** /*_argv*/){
            this->connections.push_back(
                event::Events::ConnectPreRender(
                    std::bind(&SystemGUI::Update, this)));
        }
        
        //---------------------------------//
        // Called once after Load
        private: void Init(){
        }
        
        //---------------------------------//
        // Called every Prerender event. See the Load function
        private: void Update(){
            if (!this->userCam){
                // Get a pointer to the active user camera
                this->userCam = gui::get_active_camera();
                
                // Enable saving frames
                this->userCam->EnableSaveFrame(true);
                
                // Specify the path to save frames into
                this->userCam->SetSaveFramePathname("/home/shu18/gazebo_tutorial/gazebo_frames");
            }
            
            // Get scene pointer
            rendering::ScenePtr scene = rendering::get_scene();
            
            // Wait until the scene is initialized
            if (!scene || !scene->Initialized())
                return;
            
            // Look for a specific visual by name
            if (scene->GetVisual("ground_plane"))
                std::cout << "Has ground plane visual\n";
        }
        
        // Pointer the user camera
        private: rendering::UserCameraPtr userCam;
        
        // All the event connections
        private: std::vector<event::ConnectionPtr> connections;
    };
    
    // Register this plugin with the simulator
    GZ_REGISTER_SYSTEM_PLUGIN(SystemGUI)
}
