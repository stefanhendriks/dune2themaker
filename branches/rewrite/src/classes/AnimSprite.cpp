
#include "AnimSprite.h"
#include "SDL/SDL.h"
#include "BitmapList.h"
#include "Bitmap.h"

AnimSprite::AnimSprite()
{
	m_CurrentFrame = 0;
	m_TimeCounter = 0.0f;
}

void AnimSprite::AddFrame(int x, int y, int w, int h, float FrameLength)
{
	AnimSprite_FrameRecord* Frame;
	Frame = new AnimSprite_FrameRecord;
	Frame->x = x;
	Frame->y = y;
	Frame->w = w;
	Frame->h = h;
	Frame->FrameLength = FrameLength;
	m_FrameList.push_back(Frame);
}

void AnimSprite::Update_ms(int deltaTime)
{
	// we use the floating point number implementation here
	Update( (float)deltaTime / 1000.0f);
}

void AnimSprite::Update(float deltaTime)
{
	if (m_FrameList.size()==0)
		return;
	m_TimeCounter += deltaTime;
	while (m_FrameList[m_CurrentFrame]->FrameLength <= m_TimeCounter)
	{
		m_TimeCounter -= m_FrameList[m_CurrentFrame]->FrameLength;
		if (++m_CurrentFrame >= m_FrameList.size())
			m_CurrentFrame = 0;
	}
}

void AnimSprite::Render(SDL_Surface *Target)
{
	if (m_FrameList.size()==0)
		return;
	// check if the currentframe is not outside of boundaries
	assert( (m_CurrentFrame >=0) && (m_CurrentFrame < m_FrameList.size()) );

	SDL_Rect srcrect;
	AnimSprite_FrameRecord *Frame = m_FrameList[m_CurrentFrame];
	srcrect.x = Frame->x;
	srcrect.y = Frame->y;
	srcrect.w = Frame->w;
	srcrect.h = Frame->h;
	BitmapList::GetInstance()->GetBitmap(m_BitmapIndex)->Render(Target, m_xpos, m_ypos, &srcrect);
}

AnimSprite::~AnimSprite()
{
	for (unsigned int i=0; i<m_FrameList.size(); i++)
		delete m_FrameList[i];
	m_FrameList.clear();
}