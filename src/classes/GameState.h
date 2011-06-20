/*
 *  abstract Game state class
 *  created by: Peter Gaal, 2011
 *  
 *  this is a implementation of abstract state class 
 *  for a simple finite state machine
 * 
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
	virtual void OnEntry() = 0;
	virtual void OnLeave() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Update_ms(int deltaTime) = 0;
	void SetID(int ID)
	{
		m_ID = ID;
	}
	int GetID()
	{	
		return m_ID;
	}
private:
	int m_ID;
};



#endif
