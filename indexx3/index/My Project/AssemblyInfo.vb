Imports System
Imports System.Reflection
Imports System.Runtime.InteropServices
Imports System.Globalization
Imports System.Resources
Imports System.Windows

' La información general sobre un ensamblado se controla mediante el siguiente 
' conjuntos de atributos. Cambie los valores de estos atributos para modificar la información
' asociada con un ensamblado.

' Revisar los valores de los atributos del ensamblado

<Assembly: AssemblyTitle("index")> 
<Assembly: AssemblyDescription("")> 
<Assembly: AssemblyCompany("")> 
<Assembly: AssemblyProduct("index")> 
<Assembly: AssemblyCopyright("Copyright ©  2017")> 
<Assembly: AssemblyTrademark("")> 
<Assembly: ComVisible(false)>

'Para comenzar a generar aplicaciones que se puedan traducir, establezca 
'<UICulture>CultureYouAreCodingWith</UICulture> en el archivo .csproj
'dentro de <PropertyGroup>. Por ejemplo, si utiliza inglés de EE.UU.
'en los archivos de código fuente, establezca < UICulture> en en-US. A continuación, quite la marca de comentario
'del atributo NeutralResourceLanguage. Actualice "en-US" en
'la siguiente línea para que coincida con el valor UICulture del archivo de proyecto.

'<Ensamblado: NeutralResourcesLanguage("en-US", UltimateResourceFallbackLocation.Satellite)> 


'El atributo ThemeInfo describe dónde se encuentran los diccionarios de recursos genéricos y específicos de un tema.
'Primer parámetro: lugar en el que se encuentran los diccionarios de recursos específicos de un tema
'(se utiliza si no se encuentra ningún recurso en la página, 
' ni diccionarios de recursos de la aplicación)

'Segundo parámetro: lugar en el que se encuentra el diccionario de recursos genérico
'(se utiliza si no se encuentra ningún recurso en la página, 
'aplicación o diccionarios de recursos específicos del tema)
<Assembly: ThemeInfo(ResourceDictionaryLocation.None, ResourceDictionaryLocation.SourceAssembly)>



'El siguiente GUID sirve como identificador de la biblioteca de tipos si este proyecto se expone a COM
<Assembly: Guid("bb385b9e-3a16-4b57-b5f6-b22cd5801b02")> 

' La información de versión de un ensamblado consta de los cuatro valores siguientes:
'
'      Versión principal
'      Versión secundaria 
'      Número de compilación
'      Revisión
'
' Puede especificar todos los valores o establecer como predeterminados los números de versión de compilación y de revisión 
' mediante el asterisco ('*'), como se muestra a continuación:
' <Assembly: AssemblyVersion("1.0.*")> 

<Assembly: AssemblyVersion("1.0.0.0")> 
<Assembly: AssemblyFileVersion("1.0.0.0")> 
