 If Not Intersect(Target, Range("B3:B65536")) Is Nothing Then
            Dim intersection As Range
            Set intersection = Intersect(Target, Range("B3:B65536"))
            'MsgBox "Changed" & intersection.Address(0,0)
            If Not IsEmpty(intersection.Value) Then
                endRow = intersection.Row
                For x = endRow - 1 To 3 Step -1
                    If Not IsEmpty(Cells(x, 2).Value) Then
                            'ActiveSheet.Range(Cells(x, 1), Cells(x, 1)).Select
                            Set range1 = ActiveSheet.Range(Cells(x, 1), Cells(x, 1))
                            Set range2 = ActiveSheet.Range(Cells(endRow, 1), Cells(endRow, 1))
                            Set appendedRange = ActiveSheet.Range(range1.Address & ":" & range2.Address)
                            range1.AutoFill Destination:=appendedRange
                            
                            Set range3 = ActiveSheet.Range(Cells(x + 1, 1), Cells(x + 1, 1))
                            Set appendedRange_2 = ActiveSheet.Range(range3.Address & ":" & range2.Address)
                            Set uncheckingRange = appendedRange_2
                            
                            uncheckingRange.Value = false
                            
                            'ActiveSheet.Range (Cells (endRow, 3), Cells (endRow, 3)).Select
        
                        Exit For
                    End If
                Next x
     
            End If
            'Goto ENEV
        End If
        
   'INSERT CHECKBOX IN THE LAST EMPTY ROW, NO MATTER WHAT - (INEFFICIENT, BUT TO RESTORE CHECKBOX, THIS HAS TO BE DONE)
   For X = 3 to 65536 step 1
       If Not IsEmpty (Cells (X,1).Value) And IsEmpty (Cells (X,2).Value) And IsEmpty (Cells (X,3).Value) Then
           Exit For
       End If
       If IsEmpty (Cells (X,1).Value) Then
           'ActiveSheet.Range(Cells(X - 1, 1), Cells(X - 1, 1)).Select
           Set range1 = ActiveSheet.Range(Cells(X - 1, 1), Cells(X - 1, 1))
           Set range2 = ActiveSheet.Range(Cells(X, 1), Cells(X, 1))
           Set appendedRange = ActiveSheet.Range(range1.Address & ":" & range2.Address)
           range1.AutoFill Destination:=appendedRange
            
           Set range3 = ActiveSheet.Range(Cells(X, 1), Cells(X, 1))
           Set appendedRange_2 = ActiveSheet.Range(range3.Address & ":" & range2.Address)
           Set uncheckingRange = appendedRange_2
            
           uncheckingRange.Value = false
            
           Exit For
       End If
   Next X