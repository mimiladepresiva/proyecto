Imports System
Imports System.IO
Imports System.Text

Class MainWindow
    Private conf As String

    Private Function StringFromRichTextBox(ByVal rtb As RichTextBox) As String
        ' TextPointer to the start of content in the RichTextBox.
        ' TextPointer to the end of content in the RichTextBox.
        Dim textRange As New TextRange(rtb.Document.ContentStart, rtb.Document.ContentEnd)

        ' The Text property on a TextRange object returns a string
        ' representing the plain text content of the TextRange.
        Return textRange.Text
    End Function

    Private Sub button_archivo_Click(sender As Object, e As RoutedEventArgs) Handles button_archivo.Click
        menu_archivo.Visibility = Windows.Visibility.Visible

    End Sub

    Private Sub button_vista_Click(sender As Object, e As RoutedEventArgs) Handles button_vista.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
        panel_vista.Visibility = Windows.Visibility.Visible
        panel_disenho.Visibility = Windows.Visibility.Hidden
        panel_info_pieza.Visibility = Windows.Visibility.Hidden
        panel_heramienta.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub button_disenho_Click(sender As Object, e As RoutedEventArgs) Handles button_disenho.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
        panel_vista.Visibility = Windows.Visibility.Hidden
        panel_disenho.Visibility = Windows.Visibility.Visible
        panel_info_pieza.Visibility = Windows.Visibility.Hidden
        panel_heramienta.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub button_informacion_pieza_Click(sender As Object, e As RoutedEventArgs) Handles button_informacion_pieza.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
        panel_vista.Visibility = Windows.Visibility.Hidden
        panel_disenho.Visibility = Windows.Visibility.Hidden
        panel_info_pieza.Visibility = Windows.Visibility.Visible
        panel_heramienta.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub button_configuracion_herramienta_Click(sender As Object, e As RoutedEventArgs) Handles button_configuracion_herramienta.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
        panel_vista.Visibility = Windows.Visibility.Hidden
        panel_disenho.Visibility = Windows.Visibility.Hidden
        panel_info_pieza.Visibility = Windows.Visibility.Hidden
        panel_heramienta.Visibility = Windows.Visibility.Visible
    End Sub

    Private Sub button_ayuda_Click(sender As Object, e As RoutedEventArgs) Handles button_ayuda.Click
        MessageBox.Show("aiudaa")
        menu_archivo.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub checkbox_vista_Isometrico_Checked(sender As Object, e As RoutedEventArgs) Handles checkbox_vista_Isometrico.Checked
        checkbox_vista_superior.IsChecked = False
        checkbox_vista_frontal.IsChecked = False
        checkbox_vista_lateral.IsChecked = False
    End Sub

    Private Sub checkbox_vista_lateral_Checked(sender As Object, e As RoutedEventArgs) Handles checkbox_vista_lateral.Checked
        checkbox_vista_Isometrico.IsChecked = False
    End Sub

    Private Sub checkbox_vista_superior_Checked(sender As Object, e As RoutedEventArgs) Handles checkbox_vista_superior.Checked
        checkbox_vista_Isometrico.IsChecked = False
    End Sub

    Private Sub checkbox_vista_frontal_Checked(sender As Object, e As RoutedEventArgs) Handles checkbox_vista_frontal.Checked
        checkbox_vista_Isometrico.IsChecked = False
    End Sub

    Private Sub textbox_info_pieza_revoluciones_KeyDown(sender As Object, e As KeyEventArgs) Handles textbox_info_pieza_revoluciones.KeyDown
        If Not IsNumeric(e.Key) Then
            e.Handled = True
        End If
    End Sub



    Private Sub RichTextBox_TextInput(ByVal sender As Object, ByVal e As System.Windows.Input.TextCompositionEventArgs)
        'TODO: Agregar implementación de controlador de eventos aquí.

    End Sub

    Private Sub radiobutton_herramienta_bancada_Checked(sender As Object, e As RoutedEventArgs) Handles radiobutton_herramienta_bancada.Checked
        ListBoxItem_id_5.Content = ""
        'ListBoxItem_id_6.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_7.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_8.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_9.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_10.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_11.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_12.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_13.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_14.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_15.Visibility = Windows.Visibility.Hidden
        'ListBoxItem_id_16.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub menuitem_nuevo_Click(sender As Object, e As RoutedEventArgs) Handles menuitem_nuevo.Click
        Dim config_inicial As New configuraciones_iniciales()
        menu_archivo.Visibility = Windows.Visibility.Hidden
        panel_texto.Visibility = Windows.Visibility.Visible
        panel_botones.Visibility = Windows.Visibility.Visible
        config_inicial.Show()

    End Sub

    Private Sub menuitem_abrir_Click(sender As Object, e As RoutedEventArgs) Handles menuitem_abrir.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub menuitem_guardar_como_Click(sender As Object, e As RoutedEventArgs) Handles menuitem_guardar_como.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub menuitem_guardar_Click(sender As Object, e As RoutedEventArgs) Handles menuitem_guardar.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub menuitem_exportar_Click(sender As Object, e As RoutedEventArgs) Handles menuitem_exportar.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub menuitem_salir_Click(sender As Object, e As RoutedEventArgs) Handles menuitem_salir.Click
        menu_archivo.Visibility = Windows.Visibility.Hidden
        panel_texto.Visibility = Windows.Visibility.Hidden
        panel_botones.Visibility = Windows.Visibility.Hidden
    End Sub

    Private Sub button_actualizar_Click(ByVal sender As Object, ByVal e As System.Windows.RoutedEventArgs)
        'TODO: Agregar mplementación de controlador de eventos aquí.
        Dim oc As Boolean = True
        Dim Carpeta As String = My.Computer.FileSystem.CurrentDirectory
        Dim rutasln As String = Carpeta + "\InterpreteCNCx3\InterpreteCNC\temp.yii"
        Dim rutaexe As String = Carpeta + "\InterpreteCNCx3\Debug\temp.yii"
        Dim rutaindex As String = Carpeta + "\temp.yii"
        Dim codigo As String
        Dim ventana_errores As New errores()
        'ventana_errores.Show()
        'MessageBox.Show(Carpeta)
        codigo = "<codigo>" + vbLf + StringFromRichTextBox(richtextbox_texto) + vbLf + "<codigo/>"
        oc = configuraciones()
        If oc = 0 Then
            MessageBox.Show("Faltan medidas de cilindro")
        Else
            conf = conf + codigo
            MessageBox.Show(conf)
            ' Create or overwrite the file.
            Dim fs0 As FileStream
            Dim fs1 As FileStream
            Dim fs2 As FileStream
            Try
                fs0 = File.Create(rutasln)
                fs1 = File.Create(rutaexe)
                fs2 = File.Create(rutaindex)

                ' Add text to the file.
                Dim info As Byte() = New UTF8Encoding(True).GetBytes(conf)
                fs0.Write(info, 0, info.Length)
                fs0.Close()
                fs1.Write(info, 0, info.Length)
                fs1.Close()
                fs2.Write(info, 0, info.Length)
                fs2.Close()
                Try
                    System.Diagnostics.Process.Start(Carpeta + "\interpreteCNCx3\Debug\interpreteCNC.exe")

                Catch ex As Exception
                    MessageBox.Show("No se ejecuto interprete")
                End Try
            Catch ex As Exception
                MessageBox.Show("No se creo archivo")
            End Try
        End If
    End Sub

    Private Sub button_depurar_Click(ByVal sender As Object, ByVal e As System.Windows.RoutedEventArgs)
        'TODO: Agregar implementación de controlador de eventos aquí.
        Dim ventana_comprobacion As New comprobacion()
        ventana_comprobacion.Show()
    End Sub

    Private Sub button_linea_linea_Click(ByVal sender As Object, ByVal e As System.Windows.RoutedEventArgs)
        'TODO: Agregar implementación de controlador de eventos aquí.
        Dim ventana_errores As New errores()
        ventana_errores.Show()
    End Sub

    Function configuraciones() As Boolean
        If chekbox_vista_cuadriculado.IsChecked Then
            conf = "<cuadricula>" + vbLf

        Else
            conf = "<cuadricula/>" + vbLf
        End If

        If checkbox_vista_escala.IsChecked Then
            conf = conf + "<escala>" + vbLf
        Else
            conf = conf + "<escala/>" + vbLf
        End If

        If checkbox_vista_frontal.IsChecked Then
            conf = conf + "<frontal>" + vbLf
        ElseIf checkbox_vista_Isometrico.IsChecked Then
            conf = conf + "<isometrico>" + vbLf
        ElseIf checkbox_vista_lateral.IsChecked Then
            conf = conf + "<lateral>" + vbLf
        ElseIf checkbox_vista_superior.IsChecked Then
            conf = conf + "<superior>" + vbLf
        End If

        If radiobutton_disenho_aristas.IsChecked Then
            conf = conf + "<taristas>" + vbLf
        ElseIf radiobutton_disenho_lineas_ocultas.IsChecked Then
            conf = conf + "<locultas>" + vbLf
        ElseIf radiobutton_disenho_solida.IsChecked Then
            conf = conf + "<solido>" + vbLf
        End If

        If textbox_info_pieza_altura.Text = "" Or textbox_info_pieza_radio.Text = "" Then
            Return 0
        End If

        conf = conf + "<altura>" + vbLf + textbox_info_pieza_altura.Text + vbLf + "<altura/>" + vbLf
        conf = conf + "<radio>" + vbLf + textbox_info_pieza_radio.Text + vbLf + "<radio/>" + vbLf
        Return 1

    End Function

    Private Sub radiobutton_herramienta_torreta_Checked(sender As Object, e As RoutedEventArgs) Handles radiobutton_herramienta_torreta.Checked
        ListBoxItem_id_5.Content = "5"
        'ListBoxItem_id_6.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_7.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_8.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_9.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_10.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_11.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_12.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_13.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_14.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_15.Visibility = Windows.Visibility.Visible
        'ListBoxItem_id_16.Visibility = Windows.Visibility.Visible
    End Sub
End Class
