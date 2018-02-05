#include "stdafx.h"
#include "SelectionMarker.h"

namespace dw
{
  SelectionMarker::SelectionMarker()
  {
    m_state = false;
  }

  void SelectionMarker::SetState(bool active)
  {
    m_state = active;
  }

};