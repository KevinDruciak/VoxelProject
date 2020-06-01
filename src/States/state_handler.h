#ifndef STATE_HANDLER_H
#define STATE_HANDLER_H

class StateHandler {
public:
    struct GameState {
        //information about state
    };
    GameState interpolate(GameState const & current, GameState const & previous, float alpha);

private:
    
};

#endif
