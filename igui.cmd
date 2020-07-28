# setState MPD : Unknown -> Stopped
igui::pipe_send processor p1
igui::pipe_send processor P1
igui::pipe_send watch buffer[0]
igui::pipe_send watchignore 1 P1
igui::pipe_send continue
# setState MPD : Stopped -> Running
# setState MPD : Running -> Stopped
igui::pipe_send list
igui::pipe_send list
igui::pipe_send list
igui::pipe_send print &buffer[b]
igui::Source_Files
igui::Status_Registers
igui::Status_Backtrace
igui::pipe_send 1000003-stack-select-frame 0
igui::pipe_send 1000004-stack-select-frame 0
igui::pipe_send 1000005-stack-select-frame 1
igui::pipe_send 1000006-stack-select-frame 0
igui::pipe_send 1000007-stack-select-frame 1
igui::pipe_send 1000008-stack-select-frame 0
