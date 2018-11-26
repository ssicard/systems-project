const express = require('express');
const bodyParser = require('body-parser');
const mysql = require('mysql');
const app = express();
const port = process.env.PORT || 5000;
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));

app.get('/api/logs', (req, res) => {
    // const connection = mysql.createConnection({
    //     host: 'localhost',
    //     port: '3306',
    //     user: 'root',
    //     password: 'password',
    //     database: 'progDB'
    // });
    // connection.connect();
    //I need to make select queries to retrieve all the requestForResource and ResponseToRequestForResource messages
    //The JSON sent to the react app needs to be structured as 
    // {
    //     requests: [
    //         {
    //             timestamp: timestamp,//timestamp string
    //             sender: sender, // who sent the request
    //             guid: guid,//the ID for the request
    //         },
    //         ...//the rest of the requests
    //     ],
    //     responses: [
    //         {
    //             timestamp: timestamp //timestamp string
    //             sender: sender, //who sent the response
    //             guid: guid//the id for the response
    //             responseTo: requestID //the id of the request this is responding to
    //         },
    //         ...//the rest of the responses
    //     ],
    //     messages: {//this is a dictionary
    //         'MESSAGEGUID':'MESSAGE'//the guid for the message is the key and the message is the value
    //     }
    // }
    // connection.query('SELECT STATEMENT', function(error, results, fields){
    //     if(error) console.log(error);
    //     const jsonResults = {};
    //     //format results into proper JSON format below.
    //     res.send(jsonResults);
    // });
    // connection.end();
    
    //this is sample data to simulate how interact with the mysql should behave.
  res.send(
      { 
          requests: [
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '0'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client D",
                guid: '2'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '3'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '4'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '5'
            },
            {
                timestamp:(new Date(2000,1,1,1,1,1,1)).toISOString(),
                sender: "Client E",
                guid: '6'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '7'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '8'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client A",
                guid: '9'
            },
        ],
        responses: 
        [
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '12',
                responseTo: '0'
            },
            {
              timestamp:(new Date).toISOString(),
              sender: "Client W",
              guid: '13',
              responseTo: '0'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '14',
                responseTo: '2'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '15',
                responseTo: '3'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '16',
                responseTo: '4'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '17',
                responseTo: '5'
            },
            {
                timestamp:(new Date(2000,1,1,1,1,1,1)).toISOString(),
                sender: "Client Z",
                guid: '18',
                responseTo: '6'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '19',
                responseTo: '7'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '20',
                responseTo: '8'
            },
            {
                timestamp:(new Date).toISOString(),
                sender: "Client Z",
                guid: '21',
                responseTo: '9'
            },
          ],
          messages: {
            '0':"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\n\n\n\n\n\n\n\n\n\n\n\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.\n",
            '2':    "Nullam sit amet interdum neque. Nulla aliquet diam ut vestibulum varius. Nunc pulvinar arcu vitae turpis ultricies consectetur. Maecenas at mi nec tellus sagittis efficitur ut eget est. Curabitur ut cursus turpis. Praesent mollis neque metus, nec cursus lorem malesuada vel. Duis ut sapien eget lacus semper tincidunt vel eget massa. In tincidunt magna eget placerat interdum. Sed nec euismod metus, vel ullamcorper orci. Cras convallis molestie felis ut eleifend. Cras libero ante, aliquet ut consectetur eget, pulvinar eget lacus. Nam pharetra efficitur dui sit amet vestibulum.", 
            '3':     "Nam consequat egestas porttitor. Praesent non turpis porttitor justo auctor aliquam. Vestibulum volutpat at nunc non semper. Pellentesque rutrum ac velit et lobortis. Proin vitae velit ante. Etiam id posuere diam, eu feugiat odio. Ut mi sapien, pharetra eget ultricies et, ultrices volutpat est. Morbi sed velit facilisis, dignissim nunc id, condimentum nisi. Sed tincidunt sollicitudin nulla, in rhoncus tellus consectetur nec. Vestibulum sollicitudin ut magna quis scelerisque.",
            '4':     "Sed sodales ultricies augue, id tincidunt ligula tincidunt eu. Donec in nisi vel nibh sollicitudin rutrum. In hendrerit accumsan rhoncus. Nam luctus nibh vitae augue aliquet, ac interdum ligula blandit. Duis tristique faucibus ante, ac mattis mauris dictum ullamcorper. Nullam auctor vehicula ligula, non ultricies nibh malesuada vitae. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla tempus dignissim mauris, vel sodales quam pellentesque auctor. Maecenas laoreet leo nec lorem consectetur, sed consectetur purus aliquam. Curabitur venenatis ac felis ac semper.",
            '5':    "Duis dui nulla, mattis vitae metus vitae, volutpat viverra est. Donec et justo ac odio dictum euismod. Fusce finibus, urna nec rhoncus pharetra, nulla velit blandit libero, id finibus libero est ut diam. In hac habitasse platea dictumst. Donec dictum semper neque eget interdum. Quisque consequat est eget laoreet vehicula. Suspendisse non massa et est fringilla egestas. Phasellus rhoncus ipsum ex, et dapibus tellus tempor id. Cras laoreet sodales purus eu condimentum. Praesent et porta ipsum.",
            '6':    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.",
            '7':    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.",
            '8':    "Nullam sit amet interdum neque. Nulla aliquet diam ut vestibulum varius. Nunc pulvinar arcu vitae turpis ultricies consectetur. Maecenas at mi nec tellus sagittis efficitur ut eget est. Curabitur ut cursus turpis. Praesent mollis neque metus, nec cursus lorem malesuada vel. Duis ut sapien eget lacus semper tincidunt vel eget massa. In tincidunt magna eget placerat interdum. Sed nec euismod metus, vel ullamcorper orci. Cras convallis molestie felis ut eleifend. Cras libero ante, aliquet ut consectetur eget, pulvinar eget lacus. Nam pharetra efficitur dui sit amet vestibulum.",
            '9':    "Nam consequat egestas porttitor. Praesent non turpis porttitor justo auctor aliquam. Vestibulum volutpat at nunc non semper. Pellentesque rutrum ac velit et lobortis. Proin vitae velit ante. Etiam id posuere diam, eu feugiat odio. Ut mi sapien, pharetra eget ultricies et, ultrices volutpat est. Morbi sed velit facilisis, dignissim nunc id, condimentum nisi. Sed tincidunt sollicitudin nulla, in rhoncus tellus consectetur nec. Vestibulum sollicitudin ut magna quis scelerisque.",
            '10':     "Nam consequat egestas porttitor. Praesent non turpis porttitor justo auctor aliquam. Vestibulum volutpat at nunc non semper. Pellentesque rutrum ac velit et lobortis. Proin vitae velit ante. Etiam id posuere diam, eu feugiat odio. Ut mi sapien, pharetra eget ultricies et, ultrices volutpat est. Morbi sed velit facilisis, dignissim nunc id, condimentum nisi. Sed tincidunt sollicitudin nulla, in rhoncus tellus consectetur nec. Vestibulum sollicitudin ut magna quis scelerisque.",
            '11':    "Sed sodales ultricies augue, id tincidunt ligula tincidunt eu. Donec in nisi vel nibh sollicitudin rutrum. In hendrerit accumsan rhoncus. Nam luctus nibh vitae augue aliquet, ac interdum ligula blandit. Duis tristique faucibus ante, ac mattis mauris dictum ullamcorper. Nullam auctor vehicula ligula, non ultricies nibh malesuada vitae. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla tempus dignissim mauris, vel sodales quam pellentesque auctor. Maecenas laoreet leo nec lorem consectetur, sed consectetur purus aliquam. Curabitur venenatis ac felis ac semper.",
            '12':    "Duis dui nulla, mattis vitae metus vitae, volutpat viverra est. Donec et justo ac odio dictum euismod. Fusce finibus, urna nec rhoncus pharetra, nulla velit blandit libero, id finibus libero est ut diam. In hac habitasse platea dictumst. Donec dictum semper neque eget interdum. Quisque consequat est eget laoreet vehicula. Suspendisse non massa et est fringilla egestas. Phasellus rhoncus ipsum ex, et dapibus tellus tempor id. Cras laoreet sodales purus eu condimentum. Praesent et porta ipsum.",
            '13':    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque finibus, enim in lobortis porta, mauris arcu iaculis ligula, eu elementum nulla risus et enim. Donec rutrum tempus nisl, at lacinia diam ultrices sit amet. Nulla facilisi. Donec aliquam augue sem, non blandit nisl gravida nec. Quisque vehicula efficitur elementum. Integer ultrices faucibus purus, sit amet varius arcu sagittis quis. Donec iaculis condimentum nulla, pharetra aliquam dolor. Praesent eleifend viverra malesuada. In vitae sapien a dui placerat maximus.",
            '14':    "Nullam sit amet interdum neque. Nulla aliquet diam ut vestibulum varius. Nunc pulvinar arcu vitae turpis ultricies consectetur. Maecenas at mi nec tellus sagittis efficitur ut eget est. Curabitur ut cursus turpis. Praesent mollis neque metus, nec cursus lorem malesuada vel. Duis ut sapien eget lacus semper tincidunt vel eget massa. In tincidunt magna eget placerat interdum. Sed nec euismod metus, vel ullamcorper orci. Cras convallis molestie felis ut eleifend. Cras libero ante, aliquet ut consectetur eget, pulvinar eget lacus. Nam pharetra efficitur dui sit amet vestibulum.",
            '15':    "Nam consequat egestas porttitor. Praesent non turpis porttitor justo auctor aliquam. Vestibulum volutpat at nunc non semper. Pellentesque rutrum ac velit et lobortis. Proin vitae velit ante. Etiam id posuere diam, eu feugiat odio. Ut mi sapien, pharetra eget ultricies et, ultrices volutpat est. Morbi sed velit facilisis, dignissim nunc id, condimentum nisi. Sed tincidunt sollicitudin nulla, in rhoncus tellus consectetur nec. Vestibulum sollicitudin ut magna quis scelerisque.",
            '16':    "Sed sodales ultricies augue, id tincidunt ligula tincidunt eu. Donec in nisi vel nibh sollicitudin rutrum. In hendrerit accumsan rhoncus. Nam luctus nibh vitae augue aliquet, ac interdum ligula blandit. Duis tristique faucibus ante, ac mattis mauris dictum ullamcorper. Nullam auctor vehicula ligula, non ultricies nibh malesuada vitae. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla tempus dignissim mauris, vel sodales quam pellentesque auctor. Maecenas laoreet leo nec lorem consectetur, sed consectetur purus aliquam. Curabitur venenatis ac felis ac semper.",
            '17':    "Duis dui nulla, mattis vitae metus vitae, volutpat viverra est. Donec et justo ac odio dictum euismod. Fusce finibus, urna nec rhoncus pharetra, nulla velit blandit libero, id finibus libero est ut diam. In hac habitasse platea dictumst. Donec dictum semper neque eget interdum. Quisque consequat est eget laoreet vehicula. Suspendisse non massa et est fringilla egestas. Phasellus rhoncus ipsum ex, et dapibus tellus tempor id. Cras laoreet sodales purus eu condimentum. Praesent et porta ipsum.",
            '18':     "Duis dui nulla, mattis vitae metus vitae, volutpat viverra est. Donec et justo ac odio dictum euismod. Fusce finibus, urna nec rhoncus pharetra, nulla velit blandit libero, id finibus libero est ut diam. In hac habitasse platea dictumst. Donec dictum semper neque eget interdum. Quisque consequat est eget laoreet vehicula. Suspendisse non massa et est fringilla egestas. Phasellus rhoncus ipsum ex, et dapibus tellus tempor id. Cras laoreet sodales purus eu condimentum. Praesent et porta ipsum.",
            '19':     "Duis dui nulla, mattis vitae metus vitae, volutpat viverra est. Donec et justo ac odio dictum euismod. Fusce finibus, urna nec rhoncus pharetra, nulla velit blandit libero, id finibus libero est ut diam. In hac habitasse platea dictumst. Donec dictum semper neque eget interdum. Quisque consequat est eget laoreet vehicula. Suspendisse non massa et est fringilla egestas. Phasellus rhoncus ipsum ex, et dapibus tellus tempor id. Cras laoreet sodales purus eu condimentum. Praesent et porta ipsum.",
            '20':     "Duis dui nulla, mattis vitae metus vitae, volutpat viverra est. Donec et justo ac odio dictum euismod. Fusce finibus, urna nec rhoncus pharetra, nulla velit blandit libero, id finibus libero est ut diam. In hac habitasse platea dictumst. Donec dictum semper neque eget interdum. Quisque consequat est eget laoreet vehicula. Suspendisse non massa et est fringilla egestas. Phasellus rhoncus ipsum ex, et dapibus tellus tempor id. Cras laoreet sodales purus eu condimentum. Praesent et porta ipsum.",
          }
      });
}); 

app.listen(port, () => console.log(`Listening on port ${port}`));