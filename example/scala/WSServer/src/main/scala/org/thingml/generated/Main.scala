/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated
import org.thingml.generated._
import org.sintef.smac._
object Main {

def main(args: Array[String]): Unit = {
//Things
val WebSocketServerScala_WSServer_server = new WebSocketServerScala(_WebSocketServerScala_server_var = null.asInstanceOf[org.thingml.utils.WSServer], WebSocket__port_var = "7681".asInstanceOf[String])
//Channels
val c_11544541 = new Channel(
WebSocketServerScala_WSServer_server.getPort("messaging_int_rec").get,
WebSocketServerScala_WSServer_server.getPort("messaging_int_send").get
)
//Starting Things
WebSocketServerScala_WSServer_server.asInstanceOf[Component].start
}

}

