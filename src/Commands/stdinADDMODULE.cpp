#include <string>
#include <iostream>

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "openframe.h"
#include "App/Application.h"
#include "Command.h"
#include "ModuleList.h"
#include "stdinCommands.h"

namespace openframe {
/**************************************************************************
 ** stdinADDMODULE Class                                                 **
 **************************************************************************/
  const int stdinADDMODULE::Execute(COMMAND_ARGUMENTS) {
    App::Application *app = static_cast<App::Application *>( ePacket->getVariable("app") );
    std::stringstream &out = *static_cast<std::stringstream *>( ePacket->getVariable("out") );

    std::string name;

    if (ePacket->getArguments().size() < 1)
      return CMDERR_SYNTAX;

    // initialize variables
    name = ePacket->getArguments()[0];

    if (app->modules()->add(name, true)) {
      out << "*** Module: " << name << " loaded." << std::endl;
    } // if
    else
      out << "*** Module: " << name << " failed to load; " << app->modules()->getError() << std::endl;

    return CMDERR_SUCCESS;
  } // stdinADDMODULE::Execute
} // namespace openframe
