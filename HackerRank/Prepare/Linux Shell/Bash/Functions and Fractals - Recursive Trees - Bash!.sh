function printline() {
 
    awk    -v linewidth="$1" -v iters="$2"   '
    function printpad(len) {
        _line="";
        for (i=1;i<=len;i++) {
            _line=_line "_";
        }
        
        return _line;
    }
    function printbody(height,linewidth,centerwidth,linesegments){
        corewidth=height*4;

        currentseg = 1
        for (h=0;h<height;h++) {
            line="";
     
            if (centerwidth==1){
                line=line "1"
            }
            else{
                line=line "1" printpad(centerwidth-2) "1"
                centerwidth=centerwidth+2;
            }
            linew=length(line)
            left=int((corewidth-linew)/2);
            right=corewidth-left-linew;             
            line=printpad(left) line printpad(right)
      
        
            lineunit=line
            for(r=1;r<linesegments;r++){
                line=line lineunit
            }
            padleft=int((linewidth-length(line))/2)
            padright=linewidth-length(line)-padleft                
            line=printpad(padleft) line printpad(padright)  "\n"
 
            printf line 
        }
        if(centerwidth==1){
            printbody(height,linewidth,3,linesegments)
        }
        else{
            return
        }
    }
    BEGIN {
        height=16
        k=1;
        centerwidth=1
        runcount=0
        printedrows=0
        while ((height>=1)&&(runcount<iters))

        {
            printbody(height,linewidth,centerwidth,k)
            printedrows=printedrows+height*2
            height=height/2
            k=k*2
            runcount=runcount+1;
            
        }
       
        for (a=0;a<(63-printedrows);a++)
          {
       
            printf printpad(linewidth) "\n"
          }
 
    }'
    
}
read -r iters
printline  100 $iters | tac