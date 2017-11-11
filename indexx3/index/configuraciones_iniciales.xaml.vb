Imports System
Imports System.IO
Imports System.Net
Imports System.Windows
Imports System.Windows.Controls
Imports System.Windows.Data
Imports System.Windows.Media
Imports System.Windows.Media.Animation
Imports System.Windows.Navigation

Partial Public Class configuraciones_iniciales
	Public Sub New()
		MyBase.New()

		Me.InitializeComponent()

		' A partir de este punto se requiere la inserción de código para la creación del objeto.
	End Sub

    Private Sub button_aceptar_Click(sender As Object, e As RoutedEventArgs) Handles button_aceptar.Click
        Me.Close()

    End Sub

    Private Sub button_cancelar_Click(sender As Object, e As RoutedEventArgs) Handles button_cancelar.Click
        Me.Close()

    End Sub
End Class
