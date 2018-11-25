/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi, <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_web_protocol_http_incoming_RequestHeadersReader_hpp
#define oatpp_web_protocol_http_incoming_RequestHeadersReader_hpp

#include "oatpp/web/protocol/http/Http.hpp"

namespace oatpp { namespace web { namespace protocol { namespace http { namespace incoming {
  
class RequestHeadersReader {
public:
  
  struct Result {
    http::RequestStartingLineStruct startingLine;
    http::Protocol::HeadersLabels headers;
    v_int32 bufferPosStart;
    v_int32 bufferPosEnd;
  };
private:
  os::io::Library::v_size readHeadersSection(const std::shared_ptr<oatpp::data::stream::IOStream>& connection,
                                             oatpp::data::stream::OutputStream* bufferStream,
                                             Result& result);
private:
  p_char8 m_buffer;
  v_int32 m_bufferSize;
  v_int32 m_maxHeadersSize;
public:
  
  Result readHeaders(const std::shared_ptr<oatpp::data::stream::IOStream>& connection, http::Status& error);
  
};
  
}}}}}

#endif /* oatpp_web_protocol_http_incoming_RequestHeadersReader_hpp */