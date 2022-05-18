#***************** ;
#circular Move ;
#--------------- ;
#for moving robot linearly to ;
#next pose in karel path ;
#***************** ;

TP_GROUPMASK = "1,*,*,*,*"
TP_COMMENT = "AM arc move"

case poseCode
  when PTH_MOVETO

    case poseType
      when PTH_TOOLING
        linear_move.to(pr1).at(speed, 'mm/s').term(FINE).
                    time_after(0.0, RUN_LASER_START())
      else
        linear_move.to(pr1).at(speed, 'mm/s').term(FINE)
    end
    
  when PTH_CLOSE
    circular_move.mid(pr1).to(pr2).at(speed, 'mm/s').term(termn)
    case poseType
      when PTH_TOOLING
        linear_move.to(pr2).at(speed, 'mm/s').term(FINE).
                    time_after(0.0, RUN_LASER_STOP())
      else
        linear_move.to(pr2).at(speed, 'mm/s').term(FINE)
    end
  else
    circular_move.mid(pr1).to(pr2).at(speed, 'mm/s').term(termn)
end
