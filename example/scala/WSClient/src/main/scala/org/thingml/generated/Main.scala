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
val Test_WSClient_test = new Test()
val WebSocketClientScala_WSClient_client = new WebSocketClientScala(_WebSocketClientScala_client_var = null.asInstanceOf[org.thingml.utils.WSClient], _WebSocketClientScala_status_var = null.asInstanceOf[Byte], WebSocket__port_var = "ws://localhost:7681".asInstanceOf[String])
val TimerScala_WSClient_timer = new TimerScala(_TimerScala_scalaTimer_var = null.asInstanceOf[org.thingml.utils.timer.Timer])
//Channels
val c_20314096 = new Channel(
Test_WSClient_test.getPort("timer").get,
TimerScala_WSClient_timer.getPort("timer").get
)
val c_2669707 = new Channel(
Test_WSClient_test.getPort("err").get,
WebSocketClientScala_WSClient_client.getPort("err").get
)
val c_7498652 = new Channel(
Test_WSClient_test.getPort("lifecycle").get,
WebSocketClientScala_WSClient_client.getPort("lifecycle").get
)
val c_32952062 = new Channel(
Test_WSClient_test.getPort("messaging").get,
WebSocketClientScala_WSClient_client.getPort("messaging").get
)
//Starting Things
Test_WSClient_test.asInstanceOf[Component].start
WebSocketClientScala_WSClient_client.asInstanceOf[Component].start
TimerScala_WSClient_timer.asInstanceOf[Component].start
}

}
