#include <unordered_map>
#include <string>
#include <memory>

class JaspiraAction {
public:
    std::string getName() const;
    void increaseCounter();
    std::string getActionPropertyString(const std::string& property) const;
    std::string getActionResource() const;
    void addMenuChild(std::shared_ptr<JaspiraAction> action);
    void addToolbarChild(std::shared_ptr<JaspiraAction> action);
    
    // Define these constants as needed
    static const std::string PROPERTY_MENU_PARENT;
    static const std::string PROPERTY_TOOLBAR_PARENT;
};

class ActionManager {
private:
    std::unordered_map<std::string, std::shared_ptr<JaspiraAction>> actions;

public:
    bool addAction(std::shared_ptr<JaspiraAction> action) {
        std::string name = action->getName();
        auto current = actions.find(name);
        
        if (current == actions.end()) {
            // Action not present yet, add to list
            current = actions.emplace(name, action).first;
        }

        // Increase reference counter
        current->second->increaseCounter();

        // Add as child to the menu parent if given
        std::string menuParentName = current->second->getActionPropertyString(JaspiraAction::PROPERTY_MENU_PARENT);
        if (!menuParentName.empty()) {
            // Check if the parent has already been registered
            auto menuParent = getAction(menuParentName);
            if (menuParent == nullptr) {
                // Create it on the fly
                menuParent = std::make_shared<JaspiraAction>(current->second->getActionResource(), menuParentName);
                addAction(menuParent);
            }
            // Register this action at its parent
            menuParent->addMenuChild(current->second);
        }

        // Add as child to the toolbar parent if given
        std::string toolbarParentName = current->second->getActionPropertyString(JaspiraAction::PROPERTY_TOOLBAR_PARENT);
        if (!toolbarParentName.empty()) {
            // Check if the parent has already been registered
            auto toolbarParent = getAction(toolbarParentName);
            if (toolbarParent == nullptr) {
                // No, create it on the fly
                toolbarParent = std::make_shared<JaspiraAction>(current->second->getActionResource(), toolbarParentName);
                addAction(toolbarParent);
            }
            // Register this action at its parent
            toolbarParent->addToolbarChild(current->second);
        }

        return current != actions.end(); // Return true if the action was already existent
    }

    std::shared_ptr<JaspiraAction> getAction(const std::string& name) {
        auto it = actions.find(name);
        if (it != actions.end()) {
            return it->second;
        }
        return nullptr;
    }
};
